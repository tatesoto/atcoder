// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// #define out(x) cout<<x<<'\n'
// #define all(v) v.begin(),v.end()
// #define rep(i,n) for(int i=0;i<(ll)(n);i++)
// template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
// template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
// const ll INF=(1LL<<60);
// const ll mod=998244353;
// using Graph = vector<vector<ll>>;
// using Network = vector<vector<pair<ll,ll>>>;
// using Grid = vector<string>;
// const vector<ll> dx = {0, 1, 0, -1};
// const vector<ll> dy = {1, 0, -1, 0};

// int main() {
    
// }
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int N, Q;
vector<Edge> edges;
vector<Edge> queries;

int parent[MAXN], uf_rank[MAXN];
long long mstWeight;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y, int weight) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (uf_rank[rootX] > uf_rank[rootY]) {
            parent[rootY] = rootX;
        } else if (uf_rank[rootX] < uf_rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            uf_rank[rootX]++;
        }
        mstWeight += weight;
    }
}

void kruskal() {
    sort(edges.begin(), edges.end());
    iota(parent, parent + N, 0);
    fill(uf_rank, uf_rank + N, 0);
    mstWeight = 0;
    for (auto& edge : edges) {
        unite(edge.u, edge.v, edge.weight);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> Q;
    edges.resize(N - 1);
    queries.resize(Q);

    for (int i = 0; i < N - 1; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }

    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].u >> queries[i].v >> queries[i].weight;
        queries[i].u--;
        queries[i].v--;
    }

    kruskal();

    vector<long long> results(Q);
    for (int i = 0; i < Q; ++i) {
        int u = queries[i].u;
        int v = queries[i].v;
        int w = queries[i].weight;

        if (find(u) != find(v)) {
            unite(u, v, w);
        }
        results[i] = mstWeight;
    }

    for (const auto& result : results) {
        cout << result << "\n";
    }

    return 0;
}

