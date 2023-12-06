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

Network G;
vector<ll> dist;

//startからdijkstra
void dijkstra(ll s){
    for(auto &x:dist){
        x = INF;
    }
    //{距離、行先}
    priority_queue<pair<ll,ll>> pq;
    pq.push({0, s});
    dist.at(s) = 0;
    while(!pq.empty()){
        pair<ll,ll> p = pq.top();
        ll d = p.first;
        ll pos = p.second;
        pq.pop();
        if(dist.at(pos) < d) continue;
        for(auto to_cost:G.at(pos)){
            ll to = to_cost.first;
            ll cost = to_cost.second;
            if(chmin(dist.at(to), dist.at(pos) + cost)){
                pq.push({dist.at(to), to});
            }
        }
    }
}

int main() {
    
}