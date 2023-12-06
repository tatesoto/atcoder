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
    ll K;cin>>K;
    vector<ll> h(N+1);
    rep(i,N) cin>>h.at(i+1);
    vector<ll> dp(N+1,INF);
    dp.at(1)=0;
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=K&&i+j<=N;j++){
            chmin(dp.at(i+j),dp.at(i)+abs(h.at(i+j)-h.at(i)));
        }
    }
    out(dp.at(N));
}