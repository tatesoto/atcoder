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
    vector<ll> a(N+1),b(N+1);
    for(ll i=1;i<=N;i++){
        cin>>a.at(i);
    }
    for(ll i=1;i<=N;i++){
        cin>>b.at(i);
    }
    vector<vector<ll>> dp(N+1,vector<ll>(3001,0));
    dp.at(0).at(0)=1;
    for(ll i=1;i<=N;i++){
        vector<ll> s(b.at(i)+1,0);
        s.at(0)=dp.at(i-1).at(0);
        for(ll j=1;j<=b.at(i);j++){
            s.at(j)=s.at(j-1)+dp.at(i-1).at(j);
        }
        for(ll j=a.at(i);j<=b.at(i);j++){
            dp.at(i).at(j)+=s.at(j)%mod;
            dp.at(i).at(j)%=mod;
        }
    }
    ll ans=0;
    rep(i,3001){
        ans+=dp.at(N).at(i);
        ans%=mod;
    }
    out(ans);
}