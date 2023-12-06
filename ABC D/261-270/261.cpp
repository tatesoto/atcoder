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

int main() {
    ll N,M;cin>>N>>M;
    vector<ll> x(N);
    rep(i,N) cin>>x.at(i);
    map<ll,ll> vonus;
    rep(i,M){
        ll c,y;
        cin>>c>>y;
        vonus[c]=y;
    }
    vector<vector<ll>> dp(N,vector<ll>(N+1,0));
    dp.at(0).at(1)=x.at(0);
    if(vonus.count(1)){
        dp.at(0).at(1)+=vonus[1];
    }
    for(ll i=0;i<N-1;i++){
        for(ll j=0;j<=i+2;j++){
            if(j==0){
                rep(k,i+2){
                    chmax(dp.at(i+1).at(j),dp.at(i).at(k));
                }
            }
            else{
                dp.at(i+1).at(j)=dp.at(i).at(j-1)+x.at(i+1);
            }
            if(vonus.count(j)){
                dp.at(i+1).at(j)+=vonus[j];
            }
        }
    }
    ll ans=0;
    rep(i,N+1){
        chmax(ans,dp.at(N-1).at(i));
    }
    out(ans);
}