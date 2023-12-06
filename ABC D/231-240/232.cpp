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
vector<vector<char>> G;
vector<vector<bool>> check;
vector<ll> dx={1,0};
vector<ll> dy={0,1};
void dfs(ll x,ll y){
    rep(i,2){
        check.at(x).at(y)=true;
        ll hx=x+dx.at(i);
        ll hy=y+dy.at(i);
        if(hx>H||hy>W) continue;
        if(G.at(hx).at(hy)=='#') continue;
        if(check.at(hx).at(hy)) continue;
        dfs(hx,hy);
    }
}

int main() {
    cin>>H>>W;
    G.resize(H+1,vector<char>(W+1));
    check.resize(H+1,vector<bool>(W+1,false));
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cin>>G.at(i).at(j);
        }
    }
    dfs(1,1);
    ll ans=-1;
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            if(check.at(i).at(j)){
                chmax(ans,i+j-1);
            }
        }
    }
    out(ans);
}