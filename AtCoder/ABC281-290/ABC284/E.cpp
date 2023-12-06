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


const ll sup=1000000;
// 深さ優先探索
vector<bool> seen;
vector<ll> dp;
ll dfs(const Graph &G, ll v) {

    dp.at(v)=1;
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G.at(v)) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dp.at(v)+=dfs(G, next_v); // 再帰的に探索
        if(dp.at(v)>=sup){
            dp.at(v)=sup;
            return dp.at(v);
        }
    }
    seen[v]=false;
    return dp.at(v);
}

int main() {
    //N頂点M辺のグラフ
    ll N,M;cin>>N>>M;
    seen.resize(N);
    dp.resize(N,-1);
    
    // グラフ入力受取 (ここでは無向グラフを想定)
    //隣接リスト
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        //a,bは辺の両端
        ll a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        //無向グラフなら以下を追加
        G[b].push_back(a);
    }
    out(dfs(G,0));
}