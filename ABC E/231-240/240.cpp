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

//隣接リスト（重みなし）
//N:頂点数、M:辺の数
//第3引数をTrueにすることで、有向グラフに 
Graph Glist_in(ll N, ll M, bool directed = false){
    Graph G(N);
    rep(i,M){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        if(!directed){
            G[b].push_back(a);
        }
    }
    return G;
}

Graph G;
ll cnt;
vector<pair<ll,ll>> range;
vector<bool> seen;
pair<ll, ll> dfs(ll s){
    seen[s] = true;
    bool leaf = true;
    ll l = INF, r = -1;
    for(auto x:G.at(s)){
        if(seen[x]) continue;
        leaf = false;
        pair<ll,ll> p = dfs(x);
        chmin(l, p.first);
        chmax(r, p.second);
    }
    if(leaf){
        pair<ll,ll> p = {cnt, cnt};
        range.at(s) = p;
        cnt++;
        return p;
    }
    range.at(s) = {l, r};
    return {l, r};
}


int main() {
    ll N;cin>>N;
    G = Glist_in(N, N-1);
    range.resize(N, {-1, -1});
    seen.resize(N, false);
    ll cnt = 1;
    dfs(0);
    rep(i, N){
        pair<ll,ll> p = range.at(i);
        out(p.first + 1<<" "<<p.second + 1);
    }
}