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
    vector<ll> H(N+1);
    rep(i, N) cin>>H[i+1];
    H[0] = INF;
    vector<ll> lastmax(N+1, 0);
    stack<ll> st;
    st.push(0);
    for(int i = 1; i <= N; i++) {
        if(H[i] < H[st.top()]) {
            lastmax[i] = st.top();
            st.push(i);
        }
        else {
            while(H[i] >= H[st.top()]) {
                st.pop();
            }
            lastmax[i] = st.top();
            st.push(i);
        }
    }
    vector<ll> dp(N+1, 0);
    dp[0] = 0;
    for(int i = 1; i <= N; i++) {
        int d = lastmax[i];
        dp[i] = (i-d)*H[i] + dp[d];
    }
    for(int i = 1; i <= N; i++) {
        out(dp[i]+1);
    }
}