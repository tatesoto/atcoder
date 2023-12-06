#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    ll sum=0;
    rep(i,N){
        ll x;
        cin>>x;
        sum+=max(0LL,x-10);
    }
    out(sum);
}