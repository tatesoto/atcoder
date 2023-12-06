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

int main() {
    //N頂点M辺のグラフ
    ll N,M;cin>>N>>M;
    ll K;cin>>K;
    // グラフ入力受取 (ここでは無向グラフを想定)
    //隣接リスト
    vector<vector<pair<ll,ll>>> G(N);
    for (ll i = 0; i < M; ++i) {
        //a,bは辺の両端
        ll a, b, c;
        cin >> a >> b>> c;
        G[a].push_back({b,c});
    }
    vector<ll> E(K);
    rep(i,K) cin>>E.at(i);
}