#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
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
    vector<vector<ll>> dp(N+1, vector<ll>(100010, INF));
    chmin(dp[0][0], 0LL);
    chmin(dp[0][v[0]], w[0]);
    rep(i, N-1) {
        for(int j = 0; j < 100010; j++) {
            chmin(dp[i+1][j], dp[i][j]);
            if(j+v[i+1] < 100010) chmin(dp[i+1][j+v[i+1]], dp[i][j] + w[i+1]);
        }
    }
    ll ans = -INF;
    rep(j, 100010) {
        if(dp[N-1][j] <= W) chmax(ans, j);
    }
    out(ans);
}