#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=1000000007;
using Graph = vector<vector<ll>>;

int main() {
    ll K;cin>>K;
    if(K%9!=0){
        out(0);
    }
    else{
        vector<ll> dp(K+1,0);
        dp.at(0)=1;
        for(ll i=1;i<=K;i++){
            for(ll j=1;(i-j>=0&&j<=9);j++){
                dp.at(i)+=dp.at(i-j)%mod;
                dp.at(i)%=mod;
            }
        }
        out(dp.at(K));
    }
}