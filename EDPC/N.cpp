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
    ll N;cin>>N;
    vector<ll> a(N);
    rep(i, N) cin>>a[i];
    vector<ll> a_sum(N+1, 0);
    rep(i, N) a_sum[i+1] = a[i] + a_sum[i];
    auto range_sum = [&](int l, int r) {
        return a_sum[r] - a_sum[l];
    };
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, INF));
    rep(i, N+1) dp[i][i] = 0;
    rep(i, N) dp[i][i+1] = 0;
    for(int d = 2; d <= N; d++) {
        rep(i, N+1) {
            for(int k = 1; k <= d-1; k++) {
                if(i+d <= N) chmin(dp[i][i+d], dp[i][i+k] + dp[i+k][i+d] + range_sum(i, i+d));
            }
        }
    }
    out(dp[0][N]);
}