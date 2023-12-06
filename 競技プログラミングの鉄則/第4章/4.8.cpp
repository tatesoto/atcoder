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
    ll N,M;
    cin>>N>>M;
    vector<ll> T(M+1);
    for(ll i=1;i<=M;i++){
        vector<ll> t;
        rep(j,N){
            ll a;cin>>a;
            t.push_back(a);
        }
        reverse(all(t));

        ll sum=0;
        rep(j,N){
            sum*=2;
            sum+=t.at(j);
        }
        T.at(i)=sum;
    }

    vector<vector<ll>> dp(M+1,vector<ll>((1<<N),INF));
    dp.at(0).at(0)=0;
    for(ll i=0;i<=M-1;i++){
        for(ll j=0;j<(1<<N);j++){
            chmin(dp.at(i+1).at(j),dp.at(i).at(j));
            chmin(dp.at(i+1).at((j|T.at(i+1))),dp.at(i).at(j)+1);
        }
    }
    if(dp.at(M).at((1<<N)-1)>M){
        out(-1);
    }
    else{
        out(dp.at(M).at((1<<N)-1));
    }
}