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
    ll N, M;cin>>N>>M;
    vector<ll> x(N), y(N), z(N);
    rep(i, N) cin>>x[i]>>y[i]>>z[i];
    auto query = [&](ll pmx, ll pmy, ll pmz){
        vector<vector<ll>> dp(N+1, vector<ll>(M+1, -INF));
        dp[0][0] = 0;
        rep(i, N){
            rep(j, M+1){
                chmax(dp[i+1][j], dp[i][j]);
                if(j < M && dp[i][j] != -1){
                    ll d = pmx*x[i] + pmy*y[i] + pmz*z[i];
                    chmax(dp[i+1][j+1], dp[i][j] + d);
                }
            }
        }
        return dp[N][M];
    };
    ll ans = 0;
    for(int i = -1; i <= 1; i+=2){
        for(int j = -1; j <= 1; j+=2){
            for(int k = -1; k <= 1; k+=2){
                chmax(ans, query(i, j, k));
            }
        }
    }
    out(ans);
}
