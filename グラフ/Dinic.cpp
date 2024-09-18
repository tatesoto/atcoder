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
using Network = vector<vector<pair<ll,ll>>>;
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

struct Graph {
    struct Edge {
        ll to, cap, rev;
    };
    vector<vector<Edge>> G;
    vector<ll> level, iter;
    Graph(ll n) : G(n), level(n), iter(n) {}

    void add_edge(ll from, ll to, ll cap) {
        G[from].push_back({to, cap, (ll)G[to].size()});
        G[to].push_back({from, 0, (ll)G[from].size()-1});
    }

    void bfs(ll s) {
        fill(all(level), -1);
        queue<ll> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            ll v = que.front(); que.pop();
            for (auto e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    ll dfs(ll v, ll t, ll f) {
        if (v == t) return f;
        for (ll &i = iter[v]; i < (ll)G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                ll d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll max_flow(ll s, ll t) {
        ll flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(all(iter), 0);
            ll f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    }

    void show() {
        rep(i, G.size()) {
            for (auto e : G[i]) {
                cout << i << "->" << e.to << " " << e.cap << endl;
            }
        }
    }
};

int main() {
    ll L, R, M; cin >> L >> R >> M;
    Graph G(L+R+2);
    ll s = L+R, t = L+R+1;
    rep(i, M) {
        ll a, b; cin >> a >> b;
        G.add_edge(a, L+b, 1);
    }
    rep(i, L) G.add_edge(s, i, 1);
    rep(i, R) G.add_edge(L+i, t, 1);
    out(G.max_flow(s, t));

}
