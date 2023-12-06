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
    ll N;cin>>N;
    vector<ll> p(N+1),a(N+1);
    for(ll i=1;i<=N;i++){
        cin>>p.at(i)>>a.at(i);
    }
    vector<vector<ll>> dp(N+1,vector<ll>(N+2,0));
    for(ll d=N-2;d>=0;d--){
        for(ll i=1;i<=N-d;i++){
            ll j=i+d;
            if(i==1){
                dp.at(i).at(j)=dp.at(i).at(j+1);
                if(p.at(j+1)<=j+1) dp.at(i).at(j)+=a.at(j+1);
            }
            else if(j==N){
                dp.at(i).at(j)=dp.at(i-1).at(j);
                if(i-1<=p.at(i-1)) dp.at(i).at(j)+=a.at(i-1);
            }
            else{
                ll vi=0;
                ll vj=0;
                if(i-1<=p.at(i-1) && p.at(i-1)<=j) vi=a.at(i-1);
                if(i<=p.at(j+1) && p.at(j+1)<=j+1) vj=a.at(j+1);
                dp.at(i).at(j)=max(dp.at(i-1).at(j)+vi,dp.at(i).at(j+1)+vj);
            }
        }
    }
    ll ans=0;
    rep(i,N+1){
        chmax(ans,dp.at(i).at(i));
    }
    out(ans);
}