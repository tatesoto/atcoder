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
    for(ll i=1;i<=N;i++){
        cin>>a.at(i);
    }
    vector<vector<ll>> dp(N,vector<ll>(10,0));
    dp.at(0).at(a.at(1))++;
    for(ll i=1;i<=N-1;i++){
        for(ll j=0;j<=9;j++){
            dp.at(i).at((j+a.at(i+1))%10)+=dp.at(i-1).at(j);
            dp.at(i).at((j+a.at(i+1))%10)%=mod;
            dp.at(i).at((j*a.at(i+1))%10)+=dp.at(i-1).at(j);
            dp.at(i).at((j*a.at(i+1))%10)%=mod;
        }
    }
    rep(j,10){
        out(dp.at(N-1).at(j));
    }
}