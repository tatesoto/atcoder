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
    Grid G(H);
    rep(i, H) cin>>G[i];
    auto dfs = [&] (auto dfs, ll i, ll j, ll x, ll y, set<pair<ll,ll>> &s) ->  ll {
        ll res = 0;
        rep(dir, 4) {
            ll nx = x + dx[dir];
            ll ny = y + dy[dir];
            if(nx == i && ny == j) {
                ll siz = s.size();
                chmax(res, siz);
                continue;
            }
            if(nx < 0 || nx >= H | ny < 0 || ny >= W) continue;
            if(G[nx][ny] == '#') continue;
            if(s.count({nx,ny})) continue;
            s.insert({nx, ny});
            chmax(res, dfs(dfs, i, j, nx, ny, s));
            s.erase({nx, ny});
        }
        return res;
    };


    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if(G[i][j] == '#') continue;
            set<pair<ll,ll>> s;
            s.insert({i, j});
            chmax(ans, dfs(dfs, i, j, i, j, s));
        }
    }
    if(ans <= 2) out(-1);
    else out(ans);
}