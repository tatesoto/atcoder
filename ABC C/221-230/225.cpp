#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,M;
    cin>>N>>M;
    ll left=0;
    ll first;
    cin>>first;
    rep(i,N){
        ll x;
        if(i==0){
            x=first;
        }
        else{
            cin>>x;
        }
        if(x!=first+left){
            out("No");
            return 0;
        }
        for(ll j=1;j<M;j++){
            ll y;
            cin>>y;
            if(y!=x+j){
                out("No");
                return 0;
            }
        }
        left+=7;
    }
    if(first%7==0 && M!=1){
        out("No");
        return 0;
    }
    if(first%7+M>8){
        out("No");
        return 0;
    }
    out("Yes");
}