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
    ll N,W;cin>>N>>W;
    vector<ll> w(N+1),v(N+1);
    rep(i,N) cin>>w.at(i+1)>>v.at(i+1);
    //dp[i][j] i番目まで選んだとき重さがjとなるようなものうち価値最大
    vector<vector<ll>> dp(N+1,vector<ll>(W+1,0));
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<=W;j++){
            chmax(dp.at(i).at(j),dp.at(i-1).at(j));
            if(j+w.at(i)<=W) chmax(dp.at(i).at(j+w.at(i)),dp.at(i-1).at(j)+v.at(i));
        }
    }
    ll ans=-1;
    rep(i,W+1){
        chmax(ans,dp.at(N).at(i));
    }
    out(ans);
}