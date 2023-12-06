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

Graph G;
//隣接リスト（重みなし）
//N:頂点数、M:辺の数
//第3引数をTrueにすることで、有向グラフに 
Graph Glist_in(ll N, ll M, bool directed = false){
    Graph G(N);
    rep(i,M){
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        if(!directed){
            G[b].push_back(a);
        }
    }
    return G;
}

ll bfs(ll s, ll k){
    ll ans = 0;
    queue<pair<ll,ll>> q;
    set<ll> check;
    q.push({s, 0});
    check.insert(s);
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        ll pos = p.first, dist = p.second;
        ans += pos;
        if(dist == k) continue;
        for(auto x:G[pos]){
            if(check.count(x)) continue;
            check.insert(x);
            q.push({x, dist + 1});
        }
    }
    return ans;
}


int main() {
    ll N,M;cin>>N>>M;
    G = Glist_in(N+1, M);
    ll Q;cin>>Q;
    rep(i, Q){
        ll x,k;cin>>x>>k;
        out(bfs(x, k));
    }
}