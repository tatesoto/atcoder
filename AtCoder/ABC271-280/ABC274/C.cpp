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
    rep(i,N) cin>>a.at(i+1);
    vector<ll> dp(2*N+2);
    dp.at(1)=0;
    for(ll i=1;i<=N;i++){
        dp.at(2*i)=dp.at(a.at(i))+1;
        dp.at(2*i+1)=dp.at(a.at(i))+1;
    }
    for(ll i=1;i<=2*N+1;i++){
        out(dp.at(i));
    }
}