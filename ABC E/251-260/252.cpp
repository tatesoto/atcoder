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

map<pair<ll,ll>, ll> idx;

//隣接リスト（重みあり）
//N:頂点数、M:辺の数
//第3引数をTrueにすることで、有向グラフに 
Network Nlist_in(ll N, ll M, bool directed = false){
    Network G(N);
    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        G[a].push_back({b, c});
        if(!directed){
            G[b].push_back({a, c});
        }
        idx[{a, b}] = i + 1;
        idx[{b, a}] = i + 1;
    }
    return G;
}

Network G;
vector<pair<ll,ll>> dist;
void dijkstra(ll s){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, s});
    dist.at(s) = {0, -1};
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        ll d = p.first, pos = p.second;
        if(dist[pos].first < d) continue;
        for(auto to_cost:G[pos]){
            ll to = to_cost.first;
            ll cost = to_cost.second;
            if(chmin(dist.at(to).first, d + cost)){
                dist.at(to).second = pos;
                pq.push({dist.at(to).first, to});
            }
        }
    }
}

int main() {
    ll N,M;cin>>N>>M;
    dist.resize(N, {INF, -1});
    G = Nlist_in(N, M);
    dijkstra(0);
    set<ll> edge;
    for(ll i=1;i<N;i++){
        ll e = idx[{i, dist.at(i).second}];
        if(edge.count(e)) continue;
        edge.insert(e);
    }
    for(auto x:edge){
        cout<<x;
        if(x != *edge.rbegin()){
            cout<<" ";
        }
    }
    cout<<endl;
}