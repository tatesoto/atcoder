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
    ll H, W, N;cin>>H>>W>>N;
    string T;cin>>T;
    Grid G(H);
    rep(i, H) cin>>G[i];
    set<pair<ll,ll>> st;
    rep(i, H) rep(j, W) if(G[i][j] == '#') st.insert({i, j});
    vector<pair<ll,ll>> visit;
    ll x = 0, y = 0;
    visit.push_back({x, y});
    rep(i, N) {
        if(T[i] == 'U') {
            x--;
            visit.push_back({x, y});
        }
        if(T[i] == 'D') {
            x++;
            visit.push_back({x, y});
        }
        if(T[i] == 'L') {
            y--;
            visit.push_back({x, y});
        }
        if(T[i] == 'R') {
            y++;
            visit.push_back({x, y});
        }
    }
    ll cnt = 0;
    rep(i, H) rep(j, W) {
        bool judge = true;
        if(G[i][j] == '#') continue;
        for(auto [x, y] : visit) {
            if(st.count({i + x, j + y})) {
                judge = false;
                break;
            }
        }
        if(judge) cnt++;
    }
    out(cnt);
}