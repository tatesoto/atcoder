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
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

Graph G;
vector<ll> color;
vector<bool> seen;

//startを含む連結成分の二部グラフ判定
bool Is_Biparate_Graph(const Graph &G, ll s, ll cur = 0){
    seen[s] = true;
    color.at(s) = cur;
    for(auto to: G.at(s)){
        if(color.at(to) != -1){
            if(color.at(to) == cur) return false;
            continue;
        }
        if(!Is_Biparate_Graph(G, to, 1 - cur)) return false;
    }
    return true;
}

int main() {
    ll N, M;cin>>N>>M;
    vector<ll> A(M), B(M);
    rep(i, M) cin>>A[i];
    rep(i, M) cin>>B[i];
    G.resize(N);
    color.resize(N, -1);
    seen.resize(N, false);
    rep(i, M){
        ll a = A[i];
        ll b = B[i];
        a--;
        b--;
        if(a == b){
            out("No");
            return 0;
        }
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bool judge = true;
    rep(i, N){
        if(seen[i]) continue;
        if(!Is_Biparate_Graph(G, i)) judge = false;
    }
    if(judge) out("Yes");
    else out("No");
}