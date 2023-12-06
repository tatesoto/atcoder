#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll X; cin>>X;
    if(X%100==0){
        out(100);
    }
    else{
        out(100-X%100);
    }
}