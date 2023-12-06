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

ll nC3(ll n){
    ll res=1;
    rep(i,3){
        res*=(n-i);
    }
    res/=6;
    return res;
}

int main() {
    ll N;cin>>N;
    map<ll,ll> bar;
    rep(i,N){
        ll x;cin>>x;
        if(bar.count(x)){
            bar[x]++;
        }
        else{
            bar[x]=1;
        }
    }
    ll ans=0;
    for(auto p:bar){
        ll n=p.second;
        if(n>=3){
            ans+=nC3(n);
        }
    }
    out(ans);
}