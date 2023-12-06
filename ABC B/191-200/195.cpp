#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll A,B,W;
    cin>>A>>B>>W;
    W*=1000;
    ll minv,maxv;
    bool judge=false;
    rep(i,1000010){
        if(W<=B*i && W>=A*i){
            judge=true;
        }
    }
    if(!judge){
        out("UNSATISFIABLE");
        return 0;
    }
    
    rep(i,1000010){
        if(W<=B*i){
            minv=i;
            break;
        }
    }
    for(ll i=1000010;i>=1;i--){
        if(W>=A*i){
            maxv=i;
            break;
        }
    }
    out(minv<<" "<<maxv);
}