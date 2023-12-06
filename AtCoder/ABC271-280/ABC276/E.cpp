#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;

ll H,W;
ll sx,sy;
ll ccnt;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};
vector<vector<char>> G;
vector<vector<bool>> seen;
void dfs(ll x, ll y){
    seen.at(x).at(y) = true;
    rep(dir, 4){
        ll nx = x + dx.at(dir);
        ll ny = y + dy.at(dir);
        if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
        if(G.at(nx).at(ny) == '#') continue;
        if(seen.at(nx).at(ny)) continue;
        dfs(nx, ny);
    }
}

bool check(ll i){
    ll cnt = 0;
    ll nx = sx + dx.at(i);
    ll ny = sy + dy.at(i);
    if(nx < 0 || ny < 0 || nx >= H || ny >= W || G.at(nx).at(ny) == '#'){}
    else{
        ccnt++;
        dfs(nx, ny);
        rep(dir, 4){
            ll nx = sx + dx.at(dir);
            ll ny = sy + dy.at(dir);
            if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if(seen.at(nx).at(ny)){
                cnt++;
            }
        }
    }
    if(cnt - ccnt <= 0){
        return false;
    }
    else{
        return true;
    }
}


int main() {
    cin>>H>>W;
    ccnt = 0;
    G.resize(H, vector<char>(W));
    rep(i,H){
        rep(j,W){
            cin>>G.at(i).at(j);
            if(G.at(i).at(j) == 'S'){
                sx = i;
                sy = j;
            }
        }
    }
    seen.resize(H, vector<bool>(W, false));
    seen.at(sx).at(sy) = true;
    rep(i,4){
        if(check(i)){
            out("Yes");
            return 0;
        }
    }
    out("No");
}