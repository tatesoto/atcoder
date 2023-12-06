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
    ll N,L;cin>>N>>L;
    vector<ll> dp(N+1,0);
    dp.at(0)=1;
    for(ll i=0;i<N;i++){
        dp.at(i+1)+=dp.at(i);
        dp.at(i+1)%=mod;
        if(i+L<=N){
            dp.at(i+L)+=dp.at(i);
            dp.at(i+L)%=mod;
        }
    }
    out(dp.at(N));
}