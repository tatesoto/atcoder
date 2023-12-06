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
    ll N, M;cin>>N>>M;
    Network G(N);
    rep(i, M){
        int a, b, c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    vector<ll> s_to_k(N, INF), N_to_k(N, INF);
    s_to_k.at(0) = 0;
    N_to_k.at(N-1) = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto p = pq.top();pq.pop();
        ll d = p.first, pos = p.second;
        for(auto to_cost:G[pos]){
            ll to = to_cost.first;
            ll cost = to_cost.second;
            if(chmin(s_to_k.at(to), d + cost)){
                pq.push({d + cost, to});
            }
        }
    }
    pq.push({0, N-1});
    while(!pq.empty()){
        auto p = pq.top();pq.pop();
        ll d = p.first, pos = p.second;
        for(auto to_cost:G[pos]){
            ll to = to_cost.first;
            ll cost = to_cost.second;
            if(chmin(N_to_k.at(to), d + cost)){
                pq.push({d + cost, to});
            }
        }
    }
    rep(i, N){
        out(s_to_k.at(i) + N_to_k.at(i));
    }
}