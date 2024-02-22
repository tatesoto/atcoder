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
    auto f = [&](ll x) {
        ll m = M - 2*x;
        if(m < 0) return false;
        ll n = N + m/2;
        if(n >= x) return true;
        else return false;
    };
    ll ok = 0;
    ll ng = INF;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }
    out(ok);
}
