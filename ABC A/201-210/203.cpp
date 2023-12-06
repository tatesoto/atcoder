#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll a,b,c;
    cin>>a>>b>>c;
    if((a-b)*(b-c)*(c-a)!=0){
        out(0);
    }
    else{
        ll x=a^b^c;
        out(x);
    }
}