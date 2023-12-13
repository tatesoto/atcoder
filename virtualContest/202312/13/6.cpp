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
    vector<ll> l(N+2, INF),r(N+2, -INF);
    rep(i,N){
        ll x, c;cin>>x>>c;
        chmin(l[c], x);
        chmax(r[c], x);
    }
    l[N+1] = 0;
    r[N+1] = 0;

    auto dist = [&](ll i, ll x, ll dir){
        if(l[i] == INF) return 0LL;
        if(dir == 0) return abs(r[i] - x) + r[i] - l[i];
        else return abs(l[i] - x) + r[i] - l[i];
    };

    vector<vector<ll>> dp(N+2, vector<ll>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = 0;
    ll nowl = 0, nowr = 0;
    for(ll i = 0; i <= N; i++){
        if(l[i] != INF) nowl = l[i], nowr = r[i];
        if(l[i+1] == INF){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
            continue;
        }
        chmin(dp[i+1][0], dp[i][0] + dist(i+1, nowl, 0));
        chmin(dp[i+1][0], dp[i][1] + dist(i+1, nowr, 0));
        chmin(dp[i+1][1], dp[i][0] + dist(i+1, nowl, 1));
        chmin(dp[i+1][1], dp[i][1] + dist(i+1, nowr, 1));
    }
    out(min(dp[N+1][0], dp[N+1][1]));
}
