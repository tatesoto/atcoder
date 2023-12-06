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
    vector<ll> a(N+5),b(N+5);
    for(ll i=2;i<=N;i++){
        cin>>a.at(i);
    }
    for(ll i=3;i<=N;i++){
        cin>>b.at(i);
    }
    vector<ll> dp(N+5);
    dp.at(1)=0;
    dp.at(2)=a.at(2);
    for(ll i=3;i<=N;i++){
        dp.at(i)=min(dp.at(i-1)+a.at(i),dp.at(i-2)+b.at(i));
    }
    out(dp.at(N));
}