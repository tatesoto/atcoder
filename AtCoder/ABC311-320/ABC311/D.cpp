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

int main() {
    ll N, M;cin>>N>>M;
    vector<string> G(N);
    rep(i, N) cin>>G.at(i);
    vector<ll> dx = {0, 1, 0, -1};
    vector<ll> dy = {1, 0, -1, 0};

    set<P> seen;
    seen.insert({1, 1});
    queue<P> q;
    rep(i, 4) q.push({1, 1});
    while(!q.empty()){
        auto [x, y] = q.front();q.pop();
        rep(dir, 4){
            ll nx = x + dx.at(dir);
            ll ny = y + dy.at(dir);
            while(true){
                if(G[nx][ny] == '.'){
                    ll nnx = nx + dx.at(dir);
                    ll nny = ny + dy.at(dir);
                    if(G[nnx][nny] == '#'){
                        if(seen.count({nx, ny})) break;
                        seen.insert({nx, ny});
                        q.push({nx, ny});
                        break;
                    }
                    seen.insert({nx, ny});
                    nx += dx.at(dir);
                    ny += dy.at(dir);
                }
                else break;
            }
        }
    }
    out(seen.size());
}