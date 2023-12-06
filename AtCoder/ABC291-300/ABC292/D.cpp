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

//隣接リスト（重みなし）
//N:頂点数、M:辺の数
//第3引数をTrueにすることで、有向グラフに 
Graph Glist_in(ll N, ll M, bool directed = false){
    Graph G(N);
    rep(i,M){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        if(!directed){
            G[b].push_back(a);
        }
    }
    return G;
}

Graph G;
vector<ll> e_cnt;
//startからBFS
bool BFS(ll s){
    queue<ll> q;
    q.push(s);
    ll v_cnt = 0;
    ll e_sum = 0;
    e_cnt.at(s) = G[s].size();
    e_sum += e_cnt.at(s);
    v_cnt++;
    while(!q.empty()){
        ll pos = q.front();
        q.pop();
        for(auto to:G.at(pos)){
            if(e_cnt.at(to) == -1){
                e_cnt.at(to) = G[to].size();
                q.push(to);
                e_sum += e_cnt.at(to);
                v_cnt++;
            }
        }
    }
    if(v_cnt*2 == e_sum){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    ll N,M;cin>>N>>M;
    G = Glist_in(N, M);
    e_cnt.resize(N, -1);
    bool ans = true;
    rep(i, N){
        if(e_cnt.at(i) != -1) continue;
        if(!BFS(i)) ans = false;
    }
    if(ans) out("Yes");
    else out("No");
}