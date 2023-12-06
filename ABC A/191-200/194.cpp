#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll A,B;
    cin>>A>>B;
    if(A+B>=15&&B>=8){
        out(1);
    }
    else if(A+B>=10&&B>=3){
        out(2);
    }
    else if(A+B>=3){
        out(3);
    }
    else{
        out(4);
    }
}