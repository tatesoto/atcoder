#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll MOD=1000000007;
using Graph = vector<vector<ll>>;

ll fact(ll N){
    ll ans=1;
    for(ll i=1;i<=N;i++){
        ans*=i;
        ans%=MOD;
    }
    return ans;
}

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
    ll n,r;cin>>n>>r;
    ll a=fact(n);
    ll b=fact(r);
    ll c=fact(n-r);
    ll ans=a;
    b=mod_pow(b,MOD-2);
    c=mod_pow(c,MOD-2);
    ans*=b;
    ans%=MOD;
    ans*=c;
    ans%=MOD;
    out(ans);
}