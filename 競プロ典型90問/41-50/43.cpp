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
    int H,W;cin>>H>>W;
    int rs, cs, rt, ct;cin>>rs>>cs>>rt>>ct;
    vector<vector<char>> G(H+2, vector<char>(W+2, '#'));
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin>>G.at(i).at(j);
        }
    }
    const vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    queue<vector<ll>> q;
    vector<vector<vector<ll>>> turn(H+2, vector<vector<ll>>(W+2, vector<ll>(4, INF)));
    rep(dir, 4) q.push({rs, cs, dir}), turn.at(rs).at(cs).at(dir) = 0; 
    while(!q.empty()){
        auto pos = q.front();q.pop();
        int x = pos.at(0), y = pos.at(1), pre_dir = pos.at(2);
        rep(dir, 4){
            int nx = x + dx.at(dir), ny = y + dy.at(dir);
            if(G.at(nx).at(ny) == '#') continue;
            if(dir == pre_dir){
                if(chmin(turn.at(nx).at(ny).at(dir), turn.at(x).at(y).at(pre_dir))){
                    q.push({nx, ny, dir});
                }
            }
            else{
                if(chmin(turn.at(nx).at(ny).at(dir), turn.at(x).at(y).at(pre_dir)+1)){
                    q.push({nx, ny, dir});
                }
            }
        }
    }
    ll ans = INF;
    rep(dir, 4) chmin(ans, turn.at(rt).at(ct).at(dir));
    out(ans);
}