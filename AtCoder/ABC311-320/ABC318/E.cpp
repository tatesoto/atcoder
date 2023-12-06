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
    vector<vector<ll>> id(N);
    rep(i, N){
        ll x;cin>>x;x--;
        id[x].push_back(i);
    }

    auto calc = [&](vector<ll> id){
        ll n = id.size();
        if(n <= 1) return 0LL;
        ll res = 0;
        rep(i, n-1){
            ll c = id[i+1] - id[i] -1;
            res += (i+1)*(n-1-i)*c;
        }
        return res;
    };
    ll ans = 0;
    rep(i, N){
        ans += calc(id[i]);
    }
    out(ans);
}
