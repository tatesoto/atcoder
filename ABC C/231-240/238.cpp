#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

ll digit(ll N){
    ll count=0;
    while(N>0){
        count++;
        N/=10;
    }
    return count;
}

int main() {
    ll N;
    cin>>N;
    ll n=digit(N);
    ll sum=0;
    for(ll i=0;i<=n-2;i++){
        ll x=((ll)(pow(10,i)))%998244353;
        ll a=(9*x)%998244353;
        sum+=((a*(a+1))/2)%998244353;
        sum%=998244353;
    }
    if(N<10){
        out((N*(N+1))/2);
        return 0;
    }
    ll y=((ll)(pow(10,n-1)))%998244353;
    ll z=(N-y+1)%998244353;
    sum+=((z*(z+1)/2))%998244353;
    sum%=998244353;
    out(sum);
}