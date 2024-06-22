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
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

int main() {
    ll N, M;cin>>N>>M;
    vector<ll> bitcnt(61, 0);
    rep(i, 61) {
        ll p = 1LL << (i+1);
        ll q = N / p;
        ll r = N % p;
        bitcnt[i] = (q * p / 2)%mod + max(0LL, r - p / 2 + 1);
        bitcnt[i] %= mod;
    }
    ll ans = 0;
    rep(i, 61) {
        if(M & (1LL << i)) {
            ans += bitcnt[i];
            ans %= mod;
        }
    }
    out(ans);
}