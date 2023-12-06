#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    ll X;
    cin>>X;
    vector<ll> s(N+1,0); //すべて0のN+1個の配列
    for(ll i=0;i<N;i++){
        s.at(i+1)=s.at(i)+a.at(i); //帰納的に埋めていく
    }
    ll ans=0;
    ll M=s.at(N);
    ll roop=X/M;
    ans+=roop*N;
    ll mod=X%M;
    rep(i,N+1){
        if(s.at(i)>mod){
            ans+=i;
            out(ans);
            return 0;
        }
    }
}