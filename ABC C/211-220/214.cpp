#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;cin>>N;
    vector<ll> S(N),T(N),dp(N+1,0);
    rep(i,N) cin>>S.at(i);
    rep(i,N) cin>>T.at(i);
    dp.at(1)=T.at(0);
    for(ll i=1;i<N;i++){
        dp.at(i+1)=min(dp.at(i)+S.at(i-1),T.at(i));
    }
    dp.at(1)=min(dp.at(N)+S.at(N-1),T.at(0));
    for(ll i=1;i<N;i++){
        dp.at(i+1)=min(dp.at(i)+S.at(i-1),T.at(i));
    }
    rep(i,N) out(dp.at(i+1));
}