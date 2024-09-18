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

int main() {
    ll N, M, T, La, Lb; cin >> N >> M >> T >> La >> Lb;
    Graph G(N);
    rep(i, M) {
        ll a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> t(T);
    rep(i, T) cin >> t[i];
    rep(i, N) {ll a, b; cin >> a >> b;}
    Graph Tree(N);
    auto euler_tour = [&] (auto euler_tour, ll v, ll p, vector<ll> &tour, vector<ll> &indices) -> void {
        tour.push_back(v);
        indices[v] = tour.size() - 1;
        for (auto nv : G[v]) {
            if (nv == p) continue;
            Tree[v].push_back(nv);
            Tree[nv].push_back(v);
            euler_tour(euler_tour, nv, v, tour, indices);
        }
    };
    vector<ll> A;
    vector<ll> indices(N, -1);
    euler_tour(euler_tour, 0, -1, A, indices);
    while (A.size() < La) A.push_back(0);
    
}
