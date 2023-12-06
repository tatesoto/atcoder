#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll X,A,D,N;
    cin>>X>>A>>D>>N;
    if(D==0){
        cout<<abs(X-A)<<endl;
        return 0;
    }
    ll n=(X-A+D)/D;
    if(n>=1 && n<=N){
        ll a=A+(n-1)*D;
        ll b=a+D;
        cout<<min(abs(X-a),abs(X-b))<<endl;
    }
    else{
        cout<<min(abs(X-A),abs(X-A-(N-1)*D))<<endl;
    }
}