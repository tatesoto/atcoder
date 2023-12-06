#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,X;
    cin>>N>>X;
    vector<ll> a(N);
    rep(i,N){
        ll x;cin>>x;
        if(i%2==1) a.at(i)=x-1;
        else a.at(i)=x;
    }
    ll sum=0;
    rep(i,N) sum+=a.at(i);
    if(sum<=X) out("Yes");
    else out("No");
}