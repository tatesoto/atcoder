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
    ll N, M, K;cin>>N>>M>>K;
    auto f = [&](ll x, ll d) {
        return (x + d - 1) / d;
    };
    auto gcd = [&] (auto self, ll a, ll b) {
        if(a < b) swap(a, b);
        if(b == 0) return a;
        return self(self, b, a%b);
    };
    auto lcm = [&](ll a, ll b) {
        return a / gcd(gcd, a, b)* b;
    };
    auto judge = [&](ll x) {
        return f(x, N) + f(x, M) - 2*f(x, lcm(N, M)) >= K;
    };
    ll ng = 0, ok = 1e18;
    while(ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    out(ok-1);
}