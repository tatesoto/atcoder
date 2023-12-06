#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll V,T,S,D;
    cin>>V>>T>>S>>D;
    if(V*T<=D && V*S>=D){
        out("No");
    }
    else{
        out("Yes");
    }
}