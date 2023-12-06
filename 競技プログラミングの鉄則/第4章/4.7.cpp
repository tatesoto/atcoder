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
    ll N;
    cin>>N;
    vector<ll> a(N),b(N);
    for(ll i=1;i<=N-1;i++) cin>>a.at(i);
    for(ll i=1;i<=N-1;i++) cin>>b.at(i);
    vector<ll> dp(N+1,-INF);
    dp.at(1)=0;
    for(ll i=1;i<=N-1;i++){
        chmax(dp.at(a.at(i)),dp.at(i)+100);
        chmax(dp.at(b.at(i)),dp.at(i)+150);
    }
    out(dp.at(N));
}