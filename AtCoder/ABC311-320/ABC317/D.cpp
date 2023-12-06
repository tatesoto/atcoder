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
    vector<ll> X(N+1), Y(N+1), Z(N+1);
    for(int i = 1; i <= N; i++) cin>>X[i]>>Y[i]>>Z[i];
    ll M = 0;
    for(int i = 1; i <= N; i++) M += Z[i];
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        rep(j, M+1){
            chmin(dp[i][j], dp[i-1][j]);
            if(j + Z[i] > M) break;
            chmin(dp[i][j + Z[i]], dp[i-1][j] + max(0LL, (-X[i] + Y[i] +1)/2));
        }
    }
    ll ans = INF;
    ll win = (M+1)/2;
    for(int i = win; i <= M;i++){
        chmin(ans, dp[N][i]);
    }
    out(ans);
}