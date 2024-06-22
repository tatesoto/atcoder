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
    vector<vector<ll>> abc(N+1,vector<ll>(3));
    rep(i,N){
        cin>>abc.at(i+1).at(0)>>abc.at(i+1).at(1)>>abc.at(i+1).at(2);
    }
    vector<vector<ll>> dp(N+1,vector<ll>(3,-1));
    dp.at(0).at(0)=0;
    dp.at(0).at(1)=0;
    dp.at(0).at(2)=0;
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<3;j++){
            for(ll k=0;k<3;k++){
                if(k==j) continue;
                chmax(dp.at(i).at(j),dp.at(i-1).at(k)+abc.at(i).at(j));
            }
        }
    }
    ll ans=-1;
    rep(i,3){
        chmax(ans,dp.at(N).at(i));
    }
    out(ans);
}