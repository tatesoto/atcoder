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

ll N;
Graph G;
vector<ll> depth;
vector<ll> child;
ll dfs(ll s, ll p){
    ll ret = 0;
    if(p == -1) depth.at(s) = 0;
    else depth.at(s) = depth.at(p) + 1;
    for(auto next:G[s]){
        if(depth.at(next) != -1) continue;
        ret += dfs(next, s);
    }
    ret++;
    child.at(s) = ret;
    return ret;
}

int main() {
    cin>>N;
    G.resize(N);
    depth.resize(N, -1);
    child.resize(N, -1);
    vector<pair<ll,ll>> edge(N-1);
    rep(i, N-1){
        ll a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        edge.push_back({a, b});
    }
    dfs(0, -1);
    ll ans = 0;
    for(auto p:edge){
        ll a = p.first;
        ll b = p.second;
        if(depth.at(a) < depth.at(b)){
            swap(a, b);
        }
        ll cnt = child.at(a);
        ans += cnt*(N-cnt);
    }
    out(ans);
}