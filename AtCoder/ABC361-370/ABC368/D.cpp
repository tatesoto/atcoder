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
    ll N, K;cin>>N>>K;
    Graph G(N);
    rep(i, N-1) {
        ll a, b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    set<ll> s;
    ll sv = 0;
    rep(i, K) {
        ll v;cin>>v;
        v--;
        s.insert(v);
        sv = v;
    }
    vector<bool> use(N, false);
    auto dfs = [&] (auto dfs, ll v, ll p) -> void {
        if (s.count(v)) use[v] = true;
        for (auto nv : G[v]) {
            if (nv == p) continue;
            dfs(dfs, nv, v);
            if (use[nv]) use[v] = true;
        }
        return;
    };
    dfs(dfs, sv, -1);
    ll ans = 0;
    rep(i, N) {
        if (use[i]) ans++;
    }
    out(ans);

}
