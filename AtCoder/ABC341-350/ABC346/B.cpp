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
    ll w, b;cin>>w>>b;
    ll n = w+b;
    string s = "wbwbwwbwbwbw";
    string S = "";
    rep(i, 20) {
        S += s;
    }
    rep(i, S.size()) {
        ll wcnt = 0, bcnt = 0;
        if(i+n > S.size()) break;
        rep(j, n) {
            if(S[i+j] == 'w') wcnt++;
            else bcnt++;
        }
        if(wcnt == w && bcnt == b) {
            out("Yes");
            return 0;
        }
    }
    out("No");
}