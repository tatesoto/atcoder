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
    vector<vector<ll>> abc(N, vector<ll>(3, 0));
    rep(i, N){
        rep(j, 3) {
            cin>>abc[i][j];
        }
    }
    vector<vector<ll>> dp(N+1, vector<ll>(3, -INF));
    rep(j, 3) {
        dp[0][j] = abc[0][j];
    }
    rep(i, N-1) {
        rep(j, 3) {
            rep(k, 3) {
                if(j == k) continue;
                chmax(dp[i+1][j], dp[i][k] + abc[i+1][j]);
            }
        }
    }
    ll ans = -INF;
    rep(j, 3) {
        chmax(ans, dp[N-1][j]);
    }
    out(ans);
}