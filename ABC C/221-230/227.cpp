#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    ll ans=0;
    for(ll a=1;a*a*a<=N;a++){
        for(ll b=a;a*b*b<=N;b++){
            ans+=floor(N/(a*b))-b+1;
        }
    }
    out(ans);
}