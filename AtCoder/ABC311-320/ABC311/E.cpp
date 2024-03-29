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

int main() {
    ll H, W, N;cin>>H>>W>>N;
    set<pair<ll,ll>> st;
    rep(i, N){
        ll a, b;cin>>a>>b;
        a--;b--;
        st.insert(make_pair(a, b));
    }
    vector<vector<ll>> dp(H, vector<ll>(W, 0));
    rep(i, H) dp[i][0] = (st.count({i, 0}))? 0 : 1;
    rep(i, W) dp[0][i] = (st.count({0, i}))? 0 : 1;
    for(int i = 1; i < H; i++){
        for(int j = 1; j < W; j++){
            if(st.count({i, j})) dp[i][j] = 0;
            else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        }
    }
    ll ans = 0;
    rep(i, H){
        rep(j, W){
            ans += dp[i][j];
        }
    }
    out(ans);
}