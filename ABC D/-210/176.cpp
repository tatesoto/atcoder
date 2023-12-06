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

int main() {
    ll H, W;cin>>H>>W;
    ll sx, sy;cin>>sx>>sy;sx--;sy--;
    ll tx, ty;cin>>tx>>ty;tx--;ty--;
    Grid G(H);
    rep(i, H) cin>>G.at(i);
    
    deque<pair<ll,ll>> dq;
    vector<vector<ll>> cnt(H, vector<ll>(W, INF));
    dq.push_back({sx, sy});
    cnt[sx][sy] = 0;
    while(!dq.empty()){
        auto [x, y] = dq.front();dq.pop_front();
        for(int dx = -2; dx <= 2; dx++){
            for(int dy = -2; dy <= 2; dy++){
                ll nx = x + dx;
                ll ny = y + dy;
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(G[nx][ny] == '#') continue;
                if(abs(dx) + abs(dy) == 1 && chmin(cnt[nx][ny], cnt[x][y])){
                    dq.push_front({nx, ny});
                }
                else if(chmin(cnt[nx][ny], cnt[x][y] + 1)){
                    dq.push_back({nx, ny});
                }
            }
        }
    }
    if(cnt[tx][ty] == INF) out(-1);
    else out(cnt[tx][ty]);
}
