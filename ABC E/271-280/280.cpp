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
using Network = vector<vector<pair<ll,ll>>>;

//x^NをMODで割ったあまり
ll MOD = mod;
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
    ll N,P;cin>>N>>P;
    vector<ll> dp(N+1, 0);
    P = (P*mod_pow(100, mod-2)%mod + mod) % mod;
    ll Q = (1 - P + mod) % mod;
    for(ll i = 1;i <= N;i++){
        dp.at(i) = ((Q*(dp.at(i-1)) + P*dp.at(max(0LL, i - 2)) + 1)%mod +mod) % mod;
    }
    out(dp.at(N));
}