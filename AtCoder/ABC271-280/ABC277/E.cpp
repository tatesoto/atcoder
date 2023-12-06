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


//隣接リスト（重みあり）
//N:頂点数、M:辺の数
//第3引数をTrueにすることで、有向グラフに 
Network Nlist_in(ll N, ll M, bool directed = false){
    Network G(2*N);
    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        if(c == 1){
            G[a].push_back({b, c});
            if(!directed){
                G[b].push_back({a, c});
            }
        }
        else{
            G[a + N].push_back({b + N, 1 - c});
            if(!directed){
                G[b + N].push_back({a + N, 1 - c});
            }
        }
    }
    return G;
}

Network G;
vector<ll> dist;

void BinaryBFS(ll s){
    deque<ll> dq;
    dq.push_back(s);
    dist.at(s) = 0;
    while(!dq.empty()){
        ll pos = dq.front();
        dq.pop_front();
        for(auto to_cost:G.at(pos)){
            ll to = to_cost.first;
            ll cost = to_cost.second;
            if(dist.at(to) == -1){
                dist.at(to) = dist.at(pos) + cost;
                if(cost){
                    dq.push_back(to);
                }
                else{
                    dq.push_front(to);
                }
            }
        }
    }
}


int main() {
    ll N, M, K;cin>>N>>M>>K;
    G = Nlist_in(N, M);
    dist.resize(2*N, -1);
    rep(i, K){
        ll s;cin>>s;
        s--;
        G[s].push_back({s + N, 0});
        G[s + N].push_back({s, 0});
    }
    BinaryBFS(0);
    if(dist.at(N-1) == -1 && dist.at(2*N-1) == -1){
        out(-1);
    }
    else if(min(dist.at(N-1), dist.at(2*N-1)) == -1){
        out(max(dist.at(N-1), dist.at(2*N-1)));
    }
    else{
        out(min(dist.at(N-1), dist.at(2*N-1)));
    }
}