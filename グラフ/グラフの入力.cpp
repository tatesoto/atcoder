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


//隣接リスト（重みあり）
//N:頂点数、M:辺の数
//第3引数をTrueにすることで、有向グラフに 
Network Nlist_in(ll N, ll M, bool directed = false){
    Network G(N);
    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        G[a].push_back({b, c});
        if(!directed){
            G[b].push_back({a, c});
        }
    }
    return G;
}


//隣接行列（重みなし、G[i][j] = 1 なら i->j の辺が存在、G[i][j] = 0 なら辺は存在しない)
//N:頂点数、M:辺の数
//第3引数をTrueにすることで、有向グラフに
Graph Gmatrix_in(ll N, ll M, bool directed = false){
    Graph G(N, vector<ll>(N, 0));
    rep(i,M){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        G[a][b] = 1;
        if(!directed){
            G[b][a] = 1;
        }
    }
    return G;
}


//隣接行列（重みあり、G[i][j] = wight なら i->j の辺が存在、G[i][j] = INF なら辺は存在しない)
//N:頂点数、M:辺の数
//第3引数をTrueにすることで、有向グラフに
Graph Nmatrix_in(ll N, ll M, bool directed = false){
    Graph G(N, vector<ll>(N, 0));
    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        G[a][b] = c;
        if(!directed){
            G[b][a] = c;
        }
    }
    return G;
}

int main() {
    ll N,M;cin>>N>>M;
    Graph G = Glist_in(N,M,true);
    rep(i,N){
        cout<<i<<":"<<endl;
        for(auto x:G[i]){
            out(x);
        }
    }
}