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
using P = pair<ll,ll>;

const vector<ll> dx = {1, 1, -1, -1};
const vector<ll> dy = {1, -1, 1, -1};

struct Dir{
    ll u;
    ll d;
    ll l;
    ll r;
    Dir():u(INF), d(INF), l(INF), r(INF){};
    void set(ll dir, ll x){
        if(dir == 0) u = x;
        else if(dir == 1) d = x;
        else if(dir == 2) l = x;
        else r = x;
    }
    ll get(ll dir){
        if(dir == 0) return u;
        else if(dir == 1) return d;
        else if(dir == 2) return l;
        else return r;
    }
};

int main() {
    ll N;cin>>N;
    ll sx, sy;cin>>sx>>sy;sx--,sy--;
    ll tx, ty;cin>>tx>>ty;tx--,ty--;
    vector<string> S(N);
    rep(i, N) cin>>S.at(i);
    queue<pair<P,ll>> q;
    vector<vector<Dir>> dist(N, vector<Dir>(N));
    rep(dir, 4){
        q.push({{sx, sy}, dir});
    }
    dist.at(sx).at(sy).u = 0;
    dist.at(sx).at(sy).d = 0;
    dist.at(sx).at(sy).l = 0;
    dist.at(sx).at(sy).r = 0;
    while(!q.empty()){
        auto pl = q.front();q.pop();
        auto [x, y] = pl.first;
        auto d = pl.second;
        rep(dir, 4){
            ll nx = x + dx[dir];
            ll ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(S.at(nx).at(ny) == '#') continue;
            if(dist.at(nx).at(ny).get(dir) > dist.at(x).at(y).get(d) + (dir != d)){
                dist.at(nx).at(ny).set(dir, dist.at(x).at(y).get(d) + (dir != d));
                q.push({{nx, ny}, dir});
            }
        }
    }
    ll ans = INF;
    rep(dir, 4) chmin(ans, dist.at(tx).at(ty).get(dir));
    ans == INF ? out(-1):out(ans+1);
}