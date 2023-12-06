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

vector<ll> color;
vector<ll> cnt;
bool Is_Biparate_Graph(const Graph &G, ll s, ll cur = 0){
    color.at(s) = cur;
    cnt.at(cur)++;
    for(auto to: G.at(s)){
        if(color.at(to) != -1){
            if(color.at(to) == cur) return false;
            continue;
        }
        if(!Is_Biparate_Graph(G, to, 1 - cur)) return false;
    }
    return true;
}



int main() {
    ll N,M;cin>>N>>M;
    G = Glist_in(N, M);
    color.resize(N, -1);
    ll ans = N*(N-1)/2 - M;
    rep(i, N){
        if(color.at(i) >= 0) continue;
        cnt = {0, 0};
        if(Is_Biparate_Graph(G, i)){
            ans -= (cnt[0] - 1)*(cnt[0])/2;
            ans -= (cnt[1] - 1)*(cnt[1])/2;
        }
        else{
            ans = 0;
            break;
        }
    }
    out(ans);
}
