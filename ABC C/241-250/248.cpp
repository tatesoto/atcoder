#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
const ll mod=998244353;

int main() {
    ll N,M,K;
    cin>>N>>M>>K;
    vector<vector<ll>> dp(100,vector<ll>(3000,0));
    rep(i,M) dp.at(1).at(i+1)=1;
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<K;j++){
            for(ll k=1;k<=M;k++){
                if(j+k<=K){
                    dp.at(i+1).at(j+k)+=dp.at(i).at(j);
                    dp.at(i+1).at(j+k)%=mod;                   
                }
            }
        }
    }
    ll ans=0;
    for(ll i=1;i<=K;i++){
        ans+=(dp.at(N).at(i))%mod;
        ans%=mod;
    }
    out(ans);
}