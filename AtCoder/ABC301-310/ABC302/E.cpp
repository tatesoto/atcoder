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

int main() {
    ll N, Q;cin>>N>>Q;
    set<ll> isolation;
    vector<set<ll>> edge(N);
    rep(i, N){
        isolation.insert(i);
    }
    rep(i, Q){
        ll c;cin>>c;
        if(c == 1){
            ll u, v;cin>>u>>v;
            u--,v--;
            edge[u].insert(v);
            edge[v].insert(u);
            isolation.erase(u);
            isolation.erase(v);
        }
        else{
            ll v;cin>>v;
            v--;
            for(auto u:edge[v]){
                edge[u].erase(v);
                if(edge[u].size() == 0){
                    isolation.insert(u);
                }
            }
            edge[v] = {};
            isolation.insert(v);
        }
        out(isolation.size());
    }
}