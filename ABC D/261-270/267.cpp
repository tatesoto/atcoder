#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll inf=(1LL<<60);

int main() {
    ll N,M; cin>>N>>M;
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    vector<vector<ll>> dp(N,vector<ll>(M+1,-inf));
    rep(i,N) dp.at(i).at(0)=0;
    dp.at(0).at(1)=a.at(0);
    rep(i,N-1){
        rep(j,M){
            if(j>i+1) break;
            dp.at(i+1).at(j+1)=max(dp.at(i).at(j+1),dp.at(i).at(j)+(j+1)*a.at(i+1));
        }
    }
    out(dp.at(N-1).at(M));
}