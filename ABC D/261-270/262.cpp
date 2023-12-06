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
    ll N;cin>>N;
    vector<ll> a(N+1);
    for(ll i=1;i<=N;i++) cin>>a.at(i);
    ll ans=0;
    for(ll i=1;i<=N;i++){
        vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(i,vector<ll>(i+1,0)));
        dp.at(0).at(0).at(0)=1;
        for(ll j=1;j<=N;j++){
            for(ll k=0;k<i;k++){
                for(ll l=0;l<=i;l++){
                    ll m=a.at(j)%i;
                    if(l==0){
                        dp.at(j).at(k).at(l)=dp.at(j-1).at(k).at(l);
                        dp.at(j).at(k).at(l)%=mod;
                    }
                    else{
                        dp.at(j).at(k).at(l)=dp.at(j-1).at(k).at(l)+dp.at(j-1).at((k-m+i)%i).at(l-1);
                        dp.at(j).at(k).at(l)%=mod;
                    }

                }
            }
        }
        ans+=dp.at(N).at(0).at(i);
        ans%=mod;
    }
    out(ans);
}