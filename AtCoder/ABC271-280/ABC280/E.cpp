#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;

//x^NをMODで割ったあまり
ll MOD=mod;
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

ll inverse_int(ll p,ll q){
    ll r=p;
    r*=mod_pow(q,mod-2);
    r%=mod;
    return r;
}

int main() {
    ll N;cin>>N;
    ll P;cin>>P;
    vector<vector<ll>> dp(N+1);
    rep(i,N+1){
        
    }
    dp.at(0).push_back(1);
    for(ll i=0;i<N;i++){
        for(ll j=0;j<dp.at(i).size();j++){
            ll hp=N-i-j;
            ll sgm=dp.at(i).at(j);
            if(hp>1){
                dp.at(i+1)[hp-2]+=sgm*P%mod;
                dp.at(i+1)[hp-1]+=sgm*(100-P)%mod;
            }
            if(hp==1){
                dp.at(i+1)[0]+=sgm*100%mod;
            }
        }
    }
    ll p=0;
    ll ln=-1;
    rep(i,N+1){
        if(dp.at(i)[0]!=0){
            ln=i;
        }
    }
    ll m100=mod_pow(100,mod-2);
    ll pow100=mod_pow(100,ln);
    rep(i,N+1){
        if(dp.at(i).at(0)==0){
            ll now=pow100*i;
            now%=mod;
            p+=now*dp.at(i)[0];
            p%=mod;
        }
        pow100*=m100;
        pow100%=mod;
    }
    ll q=mod_pow(100,ln);
    out(inverse_int(p,q));
}