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
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0));
    for(int d = 1; d <= N; d++) {
        rep(i, N) {
            int j = i + d;
            if(j <= N) dp[i][j] = max(a[i] - dp[i+1][j], a[j-1] - dp[i][j-1]);
        }
    }
    out(dp[0][N]);
}