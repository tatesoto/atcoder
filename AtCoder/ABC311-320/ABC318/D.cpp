#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

int main() {
    ll N;cin>>N;
    Graph D(N+1, vector<ll>(N+1, 0));
    rep(i, N){
        for(int j = i+1;j < N;j++){
            ll d;cin>>d;
            D[i][j] = d;
            D[j][i] = d;
        }
    }
    set<ll> st;
    rep(i, N){
        st.insert(i);
    }
    if(N%2 == 1) st.insert(N);
    ll ans = -1;
    auto dfs = [&](auto dfs, ll tmp) -> void {
        if(st.size() <= 1){
            chmax(ans, tmp);
            return;
        }
        auto pos = *st.begin();st.erase(pos);
        set<ll> next = st;
        for(auto nx:next){
            ll x = tmp;
            x += D[pos][nx];
            st.erase(nx);
            dfs(dfs, x);
            st.insert(nx);
        }
        st.insert(pos);
    };
    dfs(dfs, 0);
    out(ans);
}
