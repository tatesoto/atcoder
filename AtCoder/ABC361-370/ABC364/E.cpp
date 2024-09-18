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
    ll X, Y; cin>>X>>Y;
    vector<ll> A(N), B(N);
    rep(i, N) cin>>A[i]>>B[i];
    // vector<vector<ll>> dp(X+2, vector<ll>(Y+2, 0));
    // for (int i = 0; i < N; i++) {
    //     vector<vector<ll>> next_dp = dp;
    //     for (int j = 0; j <= X; j++) {
    //         for (int k = 0; k <= Y; k++) {
    //             chmax(next_dp[min(X+1LL, j+A[i])][min(Y+1LL, k+B[i])], dp[j][k] + 1);
    //         }
    //     }
    //     swap(dp, next_dp);
    // }
    map<pair<ll,ll>, ll> dp;
    dp[{0, 0}] = 0;
    for (int i = 0; i < N; i++) {
        map<pair<ll,ll>, ll> next_dp;
        for (auto [p, v] : dp) {
            auto [j, k] = p;
            chmax(next_dp[{j, k}], v);
            if(j > X || k > Y) continue;
            chmax(next_dp[{min(X+1LL, j+A[i]), min(Y+1LL, k+B[i])}], v + 1);
        }
        swap(dp, next_dp);
    }
    ll ans = 0;
    for (auto [p, v] : dp) {
        chmax(ans, v);
    }
    out(ans);
}