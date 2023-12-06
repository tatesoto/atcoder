#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

using Graph = vector<vector<ll>>;


int main() {
    //N頂点M辺のグラフ
    ll N,M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    //隣接リスト
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        //a,bは辺の両端
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        //無向グラフなら以下を追加
        G[b].push_back(a);
    }

    G.clear();

    // 重み付きグラフ入力受取 (ここでは無向グラフを想定)
    //隣接リスト
    vector<vector<pair<ll,ll>>> WG(N);
    for (ll i = 0; i < M; ++i) {
        //a,bは辺の両端
        ll a, b, c;
        cin >> a >> b >> c;
        WG[a].push_back(make_pair(b,c));
        //無向グラフなら以下を追加
        WG[b].push_back(make_pair(a,c));
    }

    //隣接行列(G[i][j]：iからjに向かう辺があるなら1)
    Graph G(N);
    rep(i,M){
        //a,bは辺の両端
        ll a,b;
        cin>>a>>b;
        G[a][b]=true;
        //無向グラフなら以下を追加
        G[b][a]=true;
    }
    
}