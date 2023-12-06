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


const vector<ll> dx={1,0,-1,0};
const vector<ll> dy={0,1,0,-1};
ll H,W;
vector<string> G;

// 深さ優先探索
vector<vector<bool>> seen(H,vector<bool>(W));
void dfs(ll h,ll w) {
    seen.at(h).at(w)= true;

    rep(dir,4){ 
        ll nh=h+dx.at(dir);
        ll nw=w+dy.at(dir);
        if (nh<0||nh>=H||nw<0||nw>=W) continue;
        if (seen.at(nh).at(nw)) continue;
        if (G.at(nh).at(nw)=='#') continue;
        dfs(nh, nw);
    }
}

int main() {
    cin>>H>>W;
    G.resize(H);
    seen.resize(H,vector<bool>(W));
    ll sh,sw,gh,gw;
    rep(i,H) cin>>G.at(i);
    rep(i,H){
        rep(j,W){
            if(G.at(i).at(j)=='s'){
                sh=i;
                sw=j;
            }
            if(G.at(i).at(j)=='g'){
                gh=i;
                gw=j;
            }
        }
    }
    dfs(sh,sw);
    if(seen.at(gh).at(gw)) out("Yes");
    else out("No");
}