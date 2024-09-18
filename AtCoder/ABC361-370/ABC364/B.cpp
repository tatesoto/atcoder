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
    ll sx, sy; cin>>sx>>sy;sx--;sy--;
    Grid grid(H);
    rep(i, H) cin>>grid[i];
    string X;cin>>X;
    ll siz = X.size();
    ll nx, ny;
    nx = sx; ny = sy;
    rep(i, siz) {
        ll nextx = nx;
        ll nexty = ny;
        if(X[i] == 'U') {
            nextx--;
        }
        else if(X[i] == 'D') {
            nextx++;
        }
        else if(X[i] == 'L') {
            nexty--;
        }
        else {
            nexty++;
        }
        if(nextx < 0 || nextx >= H || nexty < 0 || nexty >= W) {
            continue;
        }
        if(grid[nextx][nexty] == '#') {
            continue;
        }
        nx = nextx;
        ny = nexty;
    }
    out(nx+1);
    out(ny+1);
}