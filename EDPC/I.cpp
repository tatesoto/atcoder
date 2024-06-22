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
    vector<ld> p(N);
    rep(i, N) cin>>p[i];
    vector<vector<ld>> dp(N, vector<ld>(N+1, 0));
    dp[0][0] = 1-p[0];
    dp[0][1] = p[0];
    for(int i = 1; i < N; i++) {
        rep(j, N+1) {
            if(j-1 >= 0) dp[i][j] += dp[i-1][j-1] * p[i];
            dp[i][j] += dp[i-1][j] * (1-p[i]);
        }
    }
    ll mid = (N+1)/2;
    ld ans = 0;
    for(int j = mid; j <= N; j++) {
        ans += dp[N-1][j];
    }
    cout << fixed << setprecision(10);
    out(ans);
}