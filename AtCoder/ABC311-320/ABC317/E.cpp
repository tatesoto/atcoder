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
    vector<vector<char>> G(H+2, vector<char>(W+2, '#'));
    ll sx, sy, gx, gy;
    for(int i = 1; i<=H;i++){
        for(int j = 1; j<=W;j++){
            cin>>G[i][j];
            if(G[i][j] == 'S') sx = i, sy = j;
            if(G[i][j] == 'G') gx = i, gy = j;
        }
    }
    for(int i = 1; i <= H; i++){
        bool wall = false;
        for(int j = 1; j <= W; j++){
            if(G[i][j] == '>'){
                wall = true;
                G[i][j] = '#';
            }
            else if(G[i][j] == '.'){
                if(wall) G[i][j] = 'x';
            }
            else if(G[i][j] != 'x'){
                wall = false;
            }
        }
    }
    for(int i = 1; i <= H; i++){
        bool wall = false;
        for(int j = W; j >= 1; j--){
            if(G[i][j] == '<'){
                wall = true;
                G[i][j] = '#';
            }
            else if(G[i][j] == '.'){
                if(wall) G[i][j] = 'x';
            }
            else if(G[i][j] != 'x'){
                wall = false;
            }
        }
    }
    for(int j = 1; j <= W; j++){
        bool wall = false;
        for(int i = 1; i <= H; i++){
            if(G[i][j] == 'v'){
                wall = true;
                G[i][j] = '#';
            }
            else if(G[i][j] == '.'){
                if(wall) G[i][j] = 'x';
            }
            else if(G[i][j] != 'x'){
                wall = false;
            }
        }
    }
    for(int j = 1; j <= W; j++){
        bool wall = false;
        for(int i = H; i >= 1; i--){
            if(G[i][j] == '^'){
                wall = true;
                G[i][j] = '#';
            }
            else if(G[i][j] == '.'){
                if(wall) G[i][j] = 'x';
            }
            else if(G[i][j] != 'x'){
                wall = false;
            }
        }
    }

    queue<pair<ll,ll>>  q;
    vector<vector<ll>> dist(H+2, vector<ll>(W+2, INF));
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while(!q.empty()){
        auto [x, y] = q.front();q.pop();
        rep(dir, 4){
            ll nx = x + dx[dir];
            ll ny = y + dy[dir];
            if(G[nx][ny] == '#' || G[nx][ny] == 'x') continue;
            if(chmin(dist[nx][ny], dist[x][y] + 1)){
                q.push({nx, ny});
            }
        }
    }
    if(dist[gx][gy] == INF) out(-1);
    else out(dist[gx][gy]);

    // rep(i, H+2)rep(j, W+2){
    //     cout<<G[i][j];
    //     if(j == W+1) cout << '\n';
    // }
}