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
    ll N, M;cin>>N>>M;
    Network to(N), from(N);
    rep(i, M) {
        ll a, b, c;cin>>a>>b>>c;
        a--, b--;
        to[b].push_back({a, c});
        from[a].push_back({b, c});
    }

    auto decoder = [&](vector<bool> v, ll id) {
        ll n = 0;
        rep(i, v.size()) {
            if(v[i]) {
                n += (1 << i);
            }
        }
        pair<ll,ll> res = {n, id};
        return res;
    };

    vector<set<ll>> visited;
    vector<vector<pair<ll,ll>>> piece;
    rep(i, N) {
        if(from[i].size() == 0) {
            vector<bool> v(N, false);
            set<ll> st;
            v[0] = true;
            st.insert(i);
            queue<pair<ll,ll>> q;
            q.push({i, 0});
            while(!q.empty()) {
                auto [id, d] = q.front();q.pop();
                for(auto [next, c] : to[d]) {
                    v[d+c] = true;
                    st.insert(next);
                    q.push({next, d+c});
                }
            }
            visited.push_back(st);
            piece.push_back(decoder(v, i));
        }
    }
    

    

}