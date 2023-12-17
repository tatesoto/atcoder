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
const vector<ll> dx = {0, 1, 0, -1, 1, 1, -1, -1};
const vector<ll> dy = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
    ll H, W;cin>>H>>W;
    Grid grid(H);
    rep(i, H) cin>>grid[i];
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    auto dfs = [&](auto self, ll y, ll x) -> void {
        visited[y][x] = true;
        rep(i, 8) {
            ll ny = y + dy[i];
            ll nx = x + dx[i];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if(grid[ny][nx] == '.') continue;
            if(visited[ny][nx]) continue;
            self(self, ny, nx);
        }
    };


    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if(grid[i][j] == '.') continue;
            if(visited[i][j]) continue;
            dfs(dfs, i, j);
            ans++;
        }
    }
    out(ans);
}