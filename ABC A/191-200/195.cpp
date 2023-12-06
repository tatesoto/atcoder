#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll M,H;
    cin>>M>>H;
    if(H%M!=0){
        out("No");
    }
    else{
        out("Yes");
    }
}