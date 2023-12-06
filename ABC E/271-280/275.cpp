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
    ll N, M, K;cin>>N>>M>>K;
    ll p = (mod_pow(M, mod-2)%mod + mod)%mod;
    vector<vector<ll>> dp(K+1, vector<ll>(N+1, 0));
    dp.at(0).at(0) = 1;
    for(ll i=0;i <= K-1;i++){
        for(ll j=0;j < N;j++){
            for(ll k=1;k<=M;k++){
                if(j + k <= N){
                    dp.at(i+1).at(j+k) += p*dp.at(i).at(j);
                    dp.at(i+1).at(j+k) = ((dp.at(i+1).at(j+k))%mod + mod)%mod;
                }
                else{
                    dp.at(i+1).at(2*N-(j+k)) += p*dp.at(i).at(j);
                    dp.at(i+1).at(2*N-(j+k))  = ((dp.at(i+1).at(2*N-(j+k)))%mod + mod)%mod;
                }
            }
        }
    }
    ll ans = 0;
    rep(i, K+1){
        ans += dp.at(i).at(N);
        ans%=mod;
    }
    out(ans);
}