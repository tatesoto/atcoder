#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

ll mod_pow(const ll &a, ll n, ll m){
    if(a%m == 0) return 0;
    if(n == 0) return 1;
    auto t = mod_pow(a, n/2, m);
    t = t*t%m;
    if(n & 1) t = t*(a%m);
    return t%m;
}

int main() {
    ll N, K, M;cin>>N>>K>>M;
    cout<<mod_pow(M, mod_pow(K, N, mod-1), mod)<<"\n";
}