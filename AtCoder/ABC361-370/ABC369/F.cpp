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
    ll H, W;cin>>H>>W;
    ll N;cin>>N;
    vector<pair<ll,ll>> P(N);
    rep(i, N) {
        ll r, c;cin>>r>>c;
        r--;c--;
        P[i] = {r, c};
    }
    vector<vector<ll>> dp(H, vector<ll>(W, 0));
    rep(i, H) {
        rep(j, W) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}
