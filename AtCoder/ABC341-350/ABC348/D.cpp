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
    vector<vector<char>> S(H, vector<char>(W, '#'));
    ll sx, sy, gx, gy;
    rep(i, H){
        rep(j, W){
            char c;cin>>c;
            S[i][j] = c;
            if(c == 'S'){
                sx = i;
                sy = j;
            }
            if(c == 'T'){
                gx = i;
                gy = j;
            }
        }
    }
    ll N;cin>>N;
    map<pair<ll,ll>,ll> mp;
    rep(i, N) {
        ll r, c, e;cin>>r>>c>>e;
        mp[{r-1, c-1}] = e;
    }
    queue<pair<ll,ll>> pq;
    pq.push({sx, sy});
    vector<vector<ll>> hp(H, vector<ll>(W, -1));
    hp[sx][sy] = 0;
    while(!pq.empty()){
        auto [x, y] = pq.front();pq.pop();
        if(mp.find({x, y}) != mp.end()) {
            if(chmax(hp[x][y], mp[{x, y}])) {
                mp[{x, y}] = -INF;
            }
        }
        rep(i, 4){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(S[nx][ny] == '#') continue;
            ll nhp = hp[x][y];
            if(nhp == 0) continue;
            if(chmax(hp[nx][ny], nhp-1)) {
                pq.push({nx, ny});
            }
        }
    }
    if(hp[gx][gy] >= 0) out("Yes");
    else out("No");
}