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
const vector<ll> dx = {1, 1, -1, -1};
const vector<ll> dy = {1, -1, -1, 1};

int main() {
    ll H, W;cin>>H>>W;
    Grid G(H);
    rep(i, H) cin>>G[i];
    auto is_valid_move = [&] (ll i, ll j) {
        return !(i < 0 || i >= H || j < 0 || j >= W);
    };
    auto check = [&] (ll i, ll j) {
        if(G[i][j] != '#') return 0LL;
        rep(dir, 4) {
            ll ni = i + dx[dir];
            ll nj = j + dy[dir];
            if(!is_valid_move(ni, nj)) return 0LL;
            if(G[ni][nj] != '#') return 0LL;
        }
        ll res = -1;
        ll nowx = i, nowy = j;
        while(is_valid_move(nowx, nowy) && G[nowx][nowy] == '#') {
            nowx = nowx + dx[0];
            nowy = nowy + dy[0];
            res++;
        }
        return res;
    };
    ll n = min(H, W);
    vector<ll> ans(n+1);
    rep(i, H) {
        rep(j, W) {
            ans[check(i, j)]++;
        }
    }
    rep(i, n) {
        out(ans[i+1]);
    }
}
