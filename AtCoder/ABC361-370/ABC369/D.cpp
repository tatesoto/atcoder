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
    vector<ll> A(N);
    rep(i, N) cin>>A[i];
    vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
    rep(i, N) {
        chmax(dp[i+1][1], dp[i][1]);
        chmax(dp[i+1][1], dp[i][0] + A[i]);
        chmax(dp[i+1][0], dp[i][0]);
        if(dp[i][1] != 0) chmax(dp[i+1][0], dp[i][1] + 2*A[i]);
    }
    out(max(dp[N][0], dp[N][1]));
}
