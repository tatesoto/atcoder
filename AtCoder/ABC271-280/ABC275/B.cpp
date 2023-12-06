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

int main() {
    vector<ll> a(6);
    rep(i,6) cin>>a.at(i);
    rep(i,6) a.at(i)%=mod;
    ll x=1;ll y=1;
    rep(i,3){
        x*=a.at(i);
        x%=mod;
        y*=a.at(i+3);
        y%=mod;
    }
    out((x-y+mod)%mod);
}