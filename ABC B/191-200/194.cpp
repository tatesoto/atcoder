#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<ll> a(N),b(N);
    rep(i,N){
        cin>>a.at(i)>>b.at(i);
    }
    ll ans=10000000;
    rep(i,N){
        rep(j,N){
            ll x;
            if(i==j){
                x=a.at(i)+b.at(j);
            }
            else{
                x=max(a.at(i),b.at(j));
            }
            ans=min(ans,x);
        }
    }
    out(ans);
}