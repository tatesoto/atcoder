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
    Graph G(N);
    rep(i, N-1){
        ll a, b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> cnt(N, 0);
    auto dfs = [&](auto self, ll v, ll p) -> void {
        for(auto nv: G[v]){
            if(nv == p) continue;
            self(self, nv, v);
            cnt[v] += cnt[nv] + 1;
        }
    };
    dfs(dfs, 0, -1);
    vector<ll> d;
    for(auto nv: G[0]){
        d.push_back(cnt[nv] + 1);
    }
    sort(all(d));
    ll ans = 1;
    rep(i, d.size()-1){
        ans += d[i];
    }
    out(ans);
}