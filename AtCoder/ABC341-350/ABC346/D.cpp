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
    vector<ll> C(N);
    rep(i, N) cin>>C[i];
    vector<vector<ll>> dp(N+1, vector<ll>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = 0;
    rep(i, N) {
        if(S[i] == '0') {
            chmin(dp[i+1][0], dp[i][1]);
            chmin(dp[i+1][1], dp[i][0] + C[i]);
        }
        else {
            chmin(dp[i+1][1], dp[i][0]);
            chmin(dp[i+1][0], dp[1][1] + C[i]);
        }
    }
    vector<vector<ll>> dp2(N+1, vector<ll>(2, INF));
    dp2[N][0] = 0;
    dp2[N][1] = 0;
    for(ll i = N-1; i >= 0; i--) {
        if(S[i] == '0') {
            chmin(dp2[i][0], dp2[i+1][1]);
            chmin(dp2[i][1], dp2[i+1][0] + C[i]);
        }
        else {
            chmin(dp2[i][1], dp2[i+1][0]);
            chmin(dp2[i][0], dp2[i+1][1] + C[i]);
        }
    }
    ll ans = INF;
    ll id = -1;
    for(int i = 1; i < N-1; i++) {
        if(chmin(ans, dp[i][0] + dp2[i][0])){
            id = i;
        }
        if(chmin(ans, dp[i][1] + dp2[i][1])){
            id = i;
        }
    }
    
    out(ans);
    out(id);
}