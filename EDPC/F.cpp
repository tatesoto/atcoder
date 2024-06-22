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
const vector<ll> dx = {0, -1, -1};
const vector<ll> dy = {-1, 0, -1};

int main() {
    string s, t;cin>>s>>t;
    ll n = s.size();
    ll m = t.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 0 || j == 0) continue;
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1] == t[j-1]) {
                chmax(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    int i = n;
    int j = m;
    string ans = "";
    while(i > 0 && j > 0) {
        if(dp[i-1][j] == dp[i][j]) {
            i--;
            continue;
        }
        if(dp[i][j-1] == dp[i][j]) {
            j--;
            continue;
        }
        if(dp[i-1][j-1] + 1 == dp[i][j]) {
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
    }
    reverse(all(ans));
    out(ans);
}