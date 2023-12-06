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
    ll N,K;cin>>N>>K;
    vector<ll> a(K);
    rep(i,K) cin>>a.at(i);
    vector<ll> dp(N+1,-1);
    dp.at(0)=0;
    for(ll i=0;i<=N;i++){
        for(ll j=0;j<K&&i-a.at(j)>=0;j++){
            chmax(dp.at(i),i-dp.at(i-a.at(j)));
        }
    }
    out(dp.at(N));
}