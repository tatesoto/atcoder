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
ll N,M;
vector<ll> dp;

ll dfs(ll x){
    if(dp[x]!=-1) return dp[x];
    ll cnt=0;
    for(auto y:G[x]){
        chmax(cnt,dfs(y)+1);
    }
    return dp[x]=cnt;
}

int main() {
    cin>>N>>M;
    // グラフ入力受取 (ここでは無向グラフを想定)
    G.resize(N);
    dp.resize(N,-1);
    //隣接リスト
    for (ll i = 0; i < M; ++i) {
        //a,bは辺の両端
        ll a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        //無向グラフなら以下を追加
    }
    ll ans=-1;
    rep(i,N){
        chmax(ans,dfs(i));
    }
    out(ans);
}