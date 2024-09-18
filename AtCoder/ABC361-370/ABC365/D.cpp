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
    string S;cin>>S;
    vector<vector<ll>> dp(N+1, vector<ll>(3, -INF));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    vector<pair<char,ll>> rsp = {{'R', 0}, {'S', 1}, {'P', 2}};
    rep(i, N) {
        if(S[i] == 'R') {
            dp[i+1][0] = max(dp[i][1], dp[i][2]);
            dp[i+1][2] = max(dp[i][0], dp[i][1]) + 1;
        }
        if(S[i] == 'S') {
            dp[i+1][1] = max(dp[i][0], dp[i][2]);
            dp[i+1][0] = max(dp[i][1], dp[i][2]) + 1;
        }
        if(S[i] == 'P') {
            dp[i+1][2] = max(dp[i][0], dp[i][1]);
            dp[i+1][1] = max(dp[i][0], dp[i][2]) + 1;
        }
    }
    ll ans = 0;
    rep(i, 3) {
        chmax(ans, dp[N][i]);
    }
    out(ans);
}