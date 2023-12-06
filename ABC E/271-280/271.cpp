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
using Network = vector<vector<pair<ll,ll>>>;


int main() {
    ll N,M,K;cin>>N>>M>>K;
    vector<vector<ll>> edge(M, vector<ll>(3));
    rep(i, M){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        edge.at(i) = {a, b, c};
    }
    vector<ll> E(K);
    rep(i,K){
        ll e;cin>>e;
        e--;
        E.at(i) = e;
    }
    vector<ll> cost(N, INF);
    cost.at(0) = 0;
    rep(i, K){
        ll from, to, length;
        from = edge.at(E.at(i)).at(0);
        to = edge.at(E.at(i)).at(1);
        length = edge.at(E.at(i)).at(2);
        chmin(cost.at(to), cost.at(from) + length);
    }
    if(cost.at(N-1) == INF) out(-1);
    else out(cost.at(N-1));
}