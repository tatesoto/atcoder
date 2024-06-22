#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
    vector<ld> p(N+1);
    rep(i,N) cin>>p.at(i+1);
    vector<vector<ld>> dp(N+1,vector<ld>(N+1,0));
    dp.at(0).at(0)=1;
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<=i;j++){
            if(j==0) dp.at(i).at(j)=dp.at(i-1).at(j)*(1-p.at(i));
            else dp.at(i).at(j)=dp.at(i-1).at(j-1)*p.at(i)+dp.at(i-1).at(j)*(1-p.at(i));
        }
    }
    ld ans=0;
    rep(i,(N+1)/2){
        ans+=dp.at(N).at(i);
    }
    cout<<fixed<<setprecision(16);
    out(1-ans);
}