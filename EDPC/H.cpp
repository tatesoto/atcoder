#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=1000000007;
using Graph = vector<vector<ll>>;

ll H,W;
const vector<ll> dh={0,1},dw={1,0};
vector<vector<char>> G;
vector<vector<ll>> dp;
ll dfs(ll h,ll w){
    if(dp.at(h).at(w)!=-1) return dp.at(h).at(w);
    ll cnt=0;
    rep(i,2){
        ll nh=h+dh.at(i);
        ll nw=w+dw.at(i);
        if(nh<0||nw<0||nh>=H||nw>=W) continue;
        if(G.at(nh).at(nw)=='#') continue;
        cnt+=dfs(nh,nw)%mod;
    }
    return dp.at(h).at(w)=cnt%mod;
}

int main() {
    cin>>H>>W;
    G.resize(H,vector<char>(W));
    rep(i,H) rep(j,W) cin>>G.at(i).at(j);
    dp.resize(H,vector<ll>(W,-1));
    dp.at(H-1).at(W-1)=1;
    dfs(0,0);
    out(dp.at(0).at(0));
}