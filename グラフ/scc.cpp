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

int N, M;
Graph G, rG; //rGは辺の向きを逆にしたグラフ
vector<ll> vs; //帰りがけ順に頂点をならべたもの
vector<bool> seen;
vector<ll> cmp; //属する強連結成分のトポロジカル順序

void dfs(int v){
    seen.at(v) = true;
    for(auto next:G[v]){
        if(!seen.at(next)) dfs(next);
    }
    vs.push_back(v);
}

void rdfs(int v, int k){
    seen.at(v) = true;
    cmp.at(v) = k;
    for(auto next:rG[v]){
        if(!seen.at(next)) rdfs(next, k);
    }
}

//強連結成分分解、強連結成分の個数を返す。O(N + M)
int scc() {
    rep(i, N) seen.at(i) = false;
    vs.clear();
    rep(i, N){
        if(!seen.at(i)) dfs(i);
    }
    rep(i, N) seen.at(i) = false;
    int k = 0;
    reverse(all(vs));
    for(auto x:vs){
        if(!seen.at(x)) rdfs(x, k++); 
    }
    return k;
}

int main() {
    cin>>N>>M;
    G.resize(N);
    rG.resize(N);
    seen.resize(N, false);
    cmp.resize(N);
    rep(i, M){
        ll a, b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        rG[b].push_back(a);
    } 
}