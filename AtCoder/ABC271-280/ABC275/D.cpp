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

ll f(ll n,map<ll,ll> &memo){
    if(n==0){
        return 1;
    }
    if(memo.count(n)){
        return memo[n];
    }
    return memo[n]=f(n/2,memo)+f(n/3,memo);
}
int main() {
    ll N;cin>>N;
    map<ll,ll> memo;
    out(f(N,memo));
}