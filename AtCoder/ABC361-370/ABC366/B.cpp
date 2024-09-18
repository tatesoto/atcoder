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
    ll M = 0;
    rep(i, N) {
        cin>>S[i];
        chmax(M, (ll)S[i].size());
    }
    vector<string> ans(M, string(N, '*'));
    rep(i, N) {
        rep(j, S[i].size()) {
            ans[j][N-i-1] = S[i][j];
        }
    }
    rep(i, M) {
        rep(j, N) {
            if(ans[i].back() == '*') {
                ans[i].pop_back();
            }
        }
        out(ans[i]);
    }

}
