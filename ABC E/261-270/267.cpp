#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N, M;cin>>N>>M;
    vector<ll> a(N);
    rep(i, N) cin>>a.at(i);
    vector<ll> v_sum(N, 0);
    Graph G(N);
    rep(i, M){
        ll u, v;cin>>u>>v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
        v_sum[u] += a[v];
        v_sum[v] += a[u];
    }
    set<pair<ll, ll>> s;
    vector<bool> erased(N, false);
    rep(i, N){
        s.insert({v_sum.at(i), i});
    }
    ll ans = -1;
    while(!s.empty()){
        auto iter = s.begin();
        auto p = *iter;
        s.erase(iter);
        if(erased[p.second]) continue;
        erased[p.second] = true;
        chmax(ans, p.first);
        for(auto &x:G[p.second]){
            if(!erased[x]){
                v_sum[x] -= a.at(p.second);
                s.insert({v_sum[x], x});
            }
        }
    }
    out(ans);
}