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
    ll N,Q;cin>>N>>Q;
    vector<ll> A;
    A.push_back(0);
    rep(i,N){
        ll x;cin>>x;
        A.push_back(x);
    }
    vector<vector<ll>> dp(30,vector<ll>(N+1,0));
    for(ll i=1;i<=N;i++){
        dp.at(0).at(i)=A.at(i);
    }
    for(ll i=0;i<29;i++){
        for(ll j=1;j<=N;j++){
            //2^(i+1)日後にいる場所=2^i日後にいる場所の2^i日後にいる場所
            dp.at(i+1).at(j)=dp.at(i).at(dp.at(i).at(j));
        }
    }
    rep(i,Q){
        ll x,y; cin>>x>>y;
        ll now=x;
        ll count=0;
        while(y>0){
            if(y&1){
                now=dp.at(count).at(now);
            }
            count++;
            y>>=1;
        }
        out(now);
    }
}