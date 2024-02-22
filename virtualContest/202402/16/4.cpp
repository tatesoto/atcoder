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
   vector<string> S(N);
    rep(i, N) cin>>S[i];
    vector<vector<ll>> dp(N + 1, vector<ll>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i = 1; i <= N; i++){
        if(S[i-1] == "AND") {
            rep(j, 2) {
                rep(x, 2) {
                    ll nj = j & x;
                    dp[i][nj] += dp[i-1][j];
                }
            }
        }
        else {
            rep(j, 2) {
                rep(x, 2) {
                    ll nj = j | x;
                    dp[i][nj] += dp[i-1][j];
                }
            }
        }
    }
    out(dp[N][1]);
}
