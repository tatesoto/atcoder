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
    ll N, W;cin>>N>>W;
    vector<ll> w(N), v(N);
    rep(i, N) cin>>w[i]>>v[i];
    vector<vector<ll>> dp(N+1, vector<ll>(W+1, -INF));
    chmax(dp[0][0], 0LL);
    if(w[0] <= W) chmax(dp[0][w[0]], v[0]);
    rep(i, N-1) {
        for(int j = 0; j <= W; j++) {
            chmax(dp[i+1][j], dp[i][j]);
            if(j + w[i+1] <= W) chmax(dp[i+1][j+w[i+1]], dp[i][j] + v[i+1]);
        }
    }
    ll ans = -INF;
    rep(j, W+1) {
        chmax(ans, dp[N-1][j]);
    }
    out(ans);
}