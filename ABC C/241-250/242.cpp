#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
const ll mod=998244353;

int main() {
    ll N;
    cin>>N;
    vector<vector<ll>> dp(N,vector<ll>(9,1));
    for(ll i=0;i<N-1;i++){
        for(ll j=0;j<9;j++){
            if(j==0){
                dp.at(i+1).at(j)=(dp.at(i).at(j)+dp.at(i).at(j+1))%mod;
            }
            else if(j==8){
                dp.at(i+1).at(j)=(dp.at(i).at(j)+dp.at(i).at(j-1))%mod;
            }
            else{
                dp.at(i+1).at(j)=(dp.at(i).at(j)+dp.at(i).at(j+1)+dp.at(i).at(j-1))%mod;
            }
        }
    }
    ll sum=0;
    rep(i,9){
        sum+=(dp.at(N-1).at(i))%mod;
    }
    out((sum)%mod);
}