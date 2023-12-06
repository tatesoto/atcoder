#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll A,B,C;
    cin>>A>>B>>C;
    if(A*A+B*B<C*C){
        out("Yes");
    }
    else{
        out("No");
    }
}