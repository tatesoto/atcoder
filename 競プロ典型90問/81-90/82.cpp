#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=1000000007;
using Graph = vector<vector<ll>>;

//x^NをMODで割ったあまり
ll MOD=1000000007;
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

ll sg(ll k,ll n){
    n%=mod; k%=mod;
    ll N=n;
    ll K=k;
    N*=n+1;
    K*=k-1;
    N%=mod;
    K%=mod;
    N*=mod_pow(2,mod-2);
    K*=mod_pow(2,mod-2);
    N%=mod;
    K%=mod;
    return (N-K+mod)%mod;
}

int main() {
    ll L,R;cin>>L>>R;
    ll ln=to_string(L).size();
    ll rn=to_string(R).size();
    if(ln==rn){
        out(sg(L,R)*ln%mod);
    }
    else{
        ll ans=0;
        ans+=ln*sg(L,mod_pow(10,ln)-1);
        ans%=mod;
        ans+=rn*sg(mod_pow(10,rn-1),R);
        ans%=mod;
        for(ll i=ln+1;i<=rn-1;i++){
            ans+=i*sg(mod_pow(10,i-1),mod_pow(10,i)-1);
            ans%=mod;
        }
        out(ans);
    }
}