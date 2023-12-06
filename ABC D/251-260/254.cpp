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

//nnの素因数の指数を2で割ったあまりに直す
ll sq_div(ll N){
    for(ll i=2;i*i<=N;i++){
        while(N%(i*i)==0){
            N/=i*i;
        }
    }
    return N;
}

int main() {
    ll N;cin>>N;
    ll ans=0;
    map<ll,ll> mp;
    for(ll i=1;i<=N;i++){
        ll n=sq_div(i);
        mp[n]++;
    }
    for(auto p:mp){
        ans+=p.second*p.second;
    }
    out(ans);
}