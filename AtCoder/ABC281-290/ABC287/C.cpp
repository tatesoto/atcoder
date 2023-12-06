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
        a--;b--;
        G[a].push_back(b);
        if(!directed){
            G[b].push_back(a);
        }
    }
    return G;
}

vector<bool> seen;

//startからDFS
void DFS(ll s){
    seen.at(s) = true;
    for(auto to:G.at(s)){
        if(seen.at(to)) continue;
        DFS(to);
    }
}

int main() {
    ll N,M;cin>>N>>M;
    G = Glist_in(N, M);
    seen.resize(N, false);
    if(N != M + 1){
        out("No");
        return 0;
    }
    for(auto v:G){
        if(v.size() >= 3){
            out("No");
            return 0;
        }
    }
    DFS(0);
    rep(i,N){
        if(!seen.at(i)){
            out("No");
            return 0;
        }
    }
    out("Yes");
}