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
    ll N; cin>>N;
    vector<ll> t(N+1,0),x(N+1,0),a(N+1,0);
    rep(i,N) cin>>t.at(i+1)>>x.at(i+1)>>a.at(i+1);
    vector<vector<ll>> dp(N+1,vector<ll>(5,0));
    ll now=0;
    rep(i,N){
        rep(j,5){
            if(j>t.at(i+1)) break;
            rep(k,5){
                if(abs(k-j)<=t.at(i+1)-now){
                    chmax(dp.at(i+1).at(j),dp.at(i).at(k));
                }
            }
            if(j==x.at(i+1)){
                dp.at(i+1).at(j)+=a.at(i+1);
            }
        }
        now=t.at(i+1);
    }
    ll ans=0;
    rep(i,5){
        chmax(ans,dp.at(N).at(i));
    }
    out(ans);
}