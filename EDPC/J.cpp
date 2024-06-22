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
    vector<ll> cnt(4, 0);
    rep(i, N) {
        ll a;cin>>a;
        cnt[a]++;
    }
    vector<vector<vector<ld>>> dp(N+2, vector<vector<ld>>(N+2, vector<ld>(N+2, 0)));
    dp[0][0][0] = 0;
    rep(i, N+1) {
        rep(j, N+1) {
            rep(k, N+1) {
                if(i == j && j == k && k == 0) continue;
                if(i-1 >= 0) dp[i][j][k] += i*dp[i-1][j+1][k];
                if(j-1 >= 0) dp[i][j][k] += j*dp[i][j-1][k+1];
                if(k-1 >= 0) dp[i][j][k] += k*dp[i][j][k-1];
                dp[i][j][k] += N;
                dp[i][j][k] /= (i+j+k);
            }
        }
    }
    cout << fixed << setprecision(16);
    out(dp[cnt[3]][cnt[2]][cnt[1]]);
}