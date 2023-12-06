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

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, ll v) {
    seen[v] = true; // v を訪問済にする
    out(v);

    // v から行ける各頂点 next_v について
    for (auto next_v : G.at(v)) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
        out(v);
    }
}

int main() {
    // 頂点数と辺数
    ll N; cin >> N;
    seen.resize(N+1,false);
    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N+1);
    for (ll i = 0; i < N-1; ++i) {
        //a,bは辺の両端
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        //無向グラフなら以下を追加
        G[b].push_back(a);
    }
    rep(i,N+1){
        sort(all(G.at(i)));
    }

    dfs(G,1);
}