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

int main() {
    ll H, W;cin>>H>>W;
    vector<vector<ll>> G(H, vector<ll>(W));
    map<char, ll> mp;
    string snuke = "snuke";
    rep(i, 5) mp[snuke.at(i)] = i;
    rep(i, H){
        rep(j, W){
            char c;cin>>c;
            if(!mp.count(c)) G[i][j] = -1;
            else G[i][j] = mp[c];
        }
    }
    if(G[0][0] < 0){
        out("No");
        return 0;
    }
    vector<ll> dx = {0, 1, 0, -1};
    vector<ll> dy = {1, 0, -1, 0};
    vector<vector<bool>> seen(H, vector<bool>(W, false));
    seen.at(0).at(0) = true;
    queue<pair<ll,ll>> q;
    q.push({0, 0});
    while(!q.empty()){
        auto [x, y] = q.front();q.pop();
        rep(dir, 4){
            ll nx = x + dx.at(dir);
            ll ny = y + dy.at(dir);
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(seen[nx][ny]) continue;
            if(G[nx][ny] < 0) continue;
            if(G[nx][ny] == (G[x][y] + 1)%5){
                seen[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    if(seen[H-1][W-1]){
        out("Yes");
    }
    else out("No");
}