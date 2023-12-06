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
    vector<ll> h(N+1);
    vector<ll> dp(N+1,INF);
    for(ll i=1;i<=N;i++){
        cin>>h.at(i);
    }
    dp.at(1)=0;
    dp.at(2)=abs(h.at(1)-h.at(2));
    for(ll i=3;i<=N;i++){
        chmin(dp.at(i),dp.at(i-1)+abs(h.at(i)-h.at(i-1)));
        chmin(dp.at(i),dp.at(i-2)+abs(h.at(i)-h.at(i-2)));
    }
    out(dp.at(N));
}