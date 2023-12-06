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

vector<bool> seen;
Graph G;
void dfs(ll x){
    seen.at(x)=true;
    for(auto next_v:G.at(x)){
        if(seen.at(next_v)) continue;
        dfs(next_v);
    }
}

int main() {
    ll N,M;cin>>N>>M;
    seen.resize(N+1,false);
    G.resize(N+1);
    rep(i,M){
        ll a,b;
        cin>>a>>b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    dfs(1LL);
    for(ll i=1;i<=N;i++){
        if(seen.at(i)) continue;
        else out("The graph is not connected.");
        return 0;
    }
    out("The graph is connected.");
}