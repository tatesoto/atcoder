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

struct info
{
    ll to;
    pair<ll,ll> dist;
};


int main() {
    ll N,M;cin>>N>>M;
    vector<vector<info>> G(N);
    rep(i, M){
        ll a, b, x, y;cin>>a>>b>>x>>y;
        a--;b--;
        G[a].push_back({b, {x, y}});
        G[b].push_back({a, {-x, -y}});
    }
    queue<ll> q;
    vector<pair<ll,ll>> place(N, {INF, INF});
    place[0] = {0, 0};
    q.push(0);
    while(!q.empty()){
        auto pos = q.front();q.pop();
        for(auto ninfo:G[pos]){
            auto [nx, dist] = ninfo;
            auto [dx, dy] = dist;
            if(place[nx].first != INF) continue;
            place[nx] = {place[pos].first + dx, place[pos].second + dy};
            q.push(nx);
        }
    }
    rep(i, N){
        auto [x, y] = place[i];
        if(x == INF) out("undecidable");
        else out(x<<" "<<y);
    }
}
