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
    vector<ld> w(5001);
    w[0] = 1;
    ld ew = (ld)9/(ld)10;
    rep(i, 5000){
        w[i+1] = w[i]*ew;
    }
    ll N;cin>>N;
    vector<ld> P(N);
    rep(i, N) cin>>P[i];
    vector<vector<ld>> dp(N+1, vector<ld>(N+1, 0));
    for(int i = N-1; i >= 0; i--){
        rep(j, N){
            chmax(dp[i][j], 0.9*(dp[i+1][j] + P[i]));
            chmax(dp[i][j], dp[i+1][j]);
        }
    }
    ld sw = 1;
    ld ans = -1;
    for(int i = 1; i <= N; i++){
        sw += w[i];
        ld r = (ld)dp[0][i]/(ld)sw - (ld)1200/(ld)sqrt(i);
        out(r);
        chmax(ans, r);
    }
    out(ans);
    rep(i, N+1){
        rep(j, N+1){
            out(dp[i][j]);
        }
    }
}