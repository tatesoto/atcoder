#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll P;
    cin>>P;
    vector<ll> a(10,1);
    rep(i,9) a.at(i+1)=a.at(i)*(i+2);
    ll count=0;
    for(ll i=9;i>=0;i--){
        if(P<=0) break;
        count+=P/a.at(i);
        P-=(P/a.at(i))*a.at(i);
    }
    out(count);
}