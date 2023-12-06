#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

//x^N
ll mypow(ll x,ll N){
    ll ans=1;
    while(N>0){
        if(N & 1){
            ans*=x;
        }
        x*=x;
        N>>=1;
    }
    return ans;
}

//x^NをMODで割ったあまり
ll MOD;
ll mod_pow(ll x,ll N){
    ll ans=1;
    while(N>0){
        if(N & 1){
            ans=ans*x%MOD;
        }
        x=x*x%MOD;
        N>>=1;
    }
    return ans;
}


int main() {
    
}