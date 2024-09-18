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
    ll N, M;cin>>N>>M;
    Graph G(N, vector<ll>(N, INF));
    struct Edge
    {
        ll from = -1;
        ll to = -1;
        ll cost = 0;
    };
    vector<Edge> edges(M);
    rep(i, M) {
        ll a, b, c;cin>>a>>b>>c;
        a--;b--;
        chmin(G[a][b], c);
        chmin(G[b][a], c);
        edges[i] = {a, b, c};
    }
    rep(i, N) G[i][i] = 0;
    vector<vector<ll>> dist = G;
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    auto query = [&] (vector<ll> B) {
        ll k = B.size();
        vector<ll> P(k);
        iota(all(P), 0);
        ll ans = INF;
        do {
            rep(bit, 1<<k) {
                vector<ll> route;
                route.push_back(0);
                rep(i, k) {
                    auto edge = edges[B[P[i]]];
                    if(bit & (1<<i)) {
                        route.push_back(edge.from);
                        route.push_back(edge.to);
                    } else {
                        route.push_back(edge.to);
                        route.push_back(edge.from);
                    }
                }
                route.push_back(N-1);
                ll sum = 0;
                rep(i, k) {
                    auto edge = edges[B[P[i]]];
                    sum += edge.cost;
                }
                for(int i = 0; i < route.size(); i += 2) {
                    sum += dist[route[i]][route[i+1]];
                }
                chmin(ans, sum);
            }
        } while(next_permutation(all(P)));
        out(ans);
    };
    ll Q;cin>>Q;
    rep(i, Q) {
        ll K;cin>>K;
        vector<ll> B(K);
        rep(j, K) cin>>B[j], B[j]--;
        query(B);
    }
}
