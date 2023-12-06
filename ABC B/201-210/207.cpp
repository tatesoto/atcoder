#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    ll x=C*D-B;
    if(x<=0) out(-1);
    else if(A%x==0) out(A/x);
    else out(A/x+1);
}