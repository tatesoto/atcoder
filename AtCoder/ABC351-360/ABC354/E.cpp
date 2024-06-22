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
    vector<ll> a(N), b(N);
    rep(i, N) cin>>a[i] >> b[i];
    vector<bool> dp(1<<N, false);
    rep(S, 1<<N) {
        rep(j, N) {
            for(int k = j+1; k < N; k++) {
                if((S >> j) & 1 || (S >> k) & 1) continue;
                if(a[j] != a[k] && b[j] != b[k]) continue;
                ll nS = S | (1 << j) | (1 << k);
                dp[nS] = dp[nS] || !dp[S];
            }
        }
    }
    if(dp[(1<<N)-1]) out("Takahashi");
    else out("Aoki");
}