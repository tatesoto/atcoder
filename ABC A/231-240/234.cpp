#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll x){
    return x*x+2*x+3;
}

int main() {
    ll t;
    cin>>t;
    ll x=f(t);
    ll y=f(x+t);
    ll z=f(x);
    cout<<f(y+z)<<endl;
}