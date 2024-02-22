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
    vector<ll> A(N), B(M);
    rep(i, N) cin>>A[i];
    rep(i, M) cin>>B[i];
    vector<ll> sumA(N + 1, 0), sumB(M + 1, 0);
    rep(i, N) sumA[i + 1] = sumA[i] + A[i];
    rep(i, M) sumB[i + 1] = sumB[i] + B[i];
    auto judge  = [&] (ll x) {
        ll tmin = INF;
        for(ll i = 0; i <= x; i++) {
            if (i > N || x - i > M) continue;
            ll t = sumA[i] + sumB[x-i];
            chmin(tmin, t);
        }
        return tmin <= K;
    };
    ll ok = 0;
    ll ng = N+M+1;
    while(ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    out(ok);
}
