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

class SegmentTree{
    public:
    //0-indexedで節点を管理する配列
    vector<ll> dat;
    ll siz=1;

    //初期化
    void init(ll N){
        //要素数を2のべき乗に
        siz=1;
        while(siz<N) siz*=2;
        //segment木の節点の数は、1+2+4+……+2^n=2^(n+1)-1 で求められる
        for(ll i=0;i<siz*2-1;i++) dat.push_back(0);
    }

    //pos番目の値(0-indexed)をxに変更する
    void update(ll pos,ll x){
        pos=pos+siz-1;
        dat.at(pos)=x;
        while(pos>0){
            pos=(pos-1)/2;
            dat.at(pos)=dat.at(pos*2+1)+dat.at(pos*2+2);
        }
    }

    //[a,b)の区間和を求める
    //kは今見ている節点の番号、l,rはその節点が[l,r)に対応していることを指す
    ll __query(ll a,ll b,ll k,ll l,ll r){
        //[a,b)と[l,r)が交差しなければINFを返す
        if(r<=a||b<=l) return 0;
        //[a,b)が[l,r)を完全に含んでいれば、この節点の値
        if(a<=l && r<=b) return dat.at(k);
        //一部が交差していれば、2つの子の最小値を返す
        else{
            ll vl=__query(a,b,k*2+1,l,(l+r)/2);
            ll vr=__query(a,b,k*2+2,(l+r)/2,r);
            return vl+vr;
        }
    }

    ll query(ll a,ll b){
        return __query(a,b,0,0,siz);
    }
};

template <typename G>
//HeavyLightDecomposition(g, root=0):rootを根とした重軽分解を構築する。
//idx(i): 頂点iのオイラーツアー順をpair(down, up)の形で返す。
//path_query(u, v, vertex, f): 可換なパスクエリを処理する。
//path_noncommutative_query(u, v, vertex, f): 非可換なパスクエリを処理する。
//subtree_query(u, vertex, f): 部分木クエリを処理する。
//lca(u, v): uとvの最小共通祖先(LCA)を返す。
struct HeavyLightDecomposition {
    private:
        //部分木の大きさを取得
        void dfs_sz(int cur) {
            size[cur] = 1;
            for (auto& dst : g[cur]) {
                if (dst == par[cur]) {
                    if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))
                        swap(g[cur][0], g[cur][1]);
                    else
                        continue;
                }
                depth[dst] = depth[cur] + 1;
                par[dst] = cur;
                dfs_sz(dst);
                size[cur] += size[dst];
                if (size[dst] > size[g[cur][0]]) {
                    swap(dst, g[cur][0]);
                }
            }
        }

        //HL分解
        void dfs_hld(int cur) {
            down[cur] = id++;
            for (auto dst : g[cur]) {
                if (dst == par[cur]) continue;
                nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));
                dfs_hld(dst);
            }
            up[cur] = id;
        }

        // [u, v)
        vector<pair<int, int>> ascend(int u, int v) const {
            vector<pair<int, int>> res;
            while (nxt[u] != nxt[v]) {
                res.emplace_back(down[u], down[nxt[u]]);
                u = par[nxt[u]];
            }
            if (u != v) res.emplace_back(down[u], down[v] + 1);
            return res;
        }

        // (u, v]
        vector<pair<int, int>> descend(int u, int v) const {
            if (u == v) return {};
            if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};
            auto res = descend(u, par[nxt[v]]);
            res.emplace_back(down[nxt[v]], down[v]);
            return res;
        }

    public:
        G& g;
        int id;
        vector<int> size, depth, down, up, nxt, par;
        //HeavyLightDecomposition(g, root=0):rootを根とした重軽分解を構築する。O(N)
        HeavyLightDecomposition(G& _g, int root = 0)
            : g(_g),
            id(0),
            size(g.size(), 0),
            depth(g.size(), 0),
            down(g.size(), -1),
            up(g.size(), -1),
            nxt(g.size(), root),
            par(g.size(), root) {
            dfs_sz(root);
            dfs_hld(root);
        }

        void build(int root) {
            dfs_sz(root);
            dfs_hld(root);
        }

        //idx(i): 頂点iのオイラーツアー順をpair(down, up)の形で返す。O(1)
        pair<int, int> idx(int i) const { return make_pair(down[i], up[i]); }

        template <typename F>
        //path_query(u, v, vertex, f): 可換なパスクエリを処理する。O(log^2 N)
        void path_query(int u, int v, bool vertex, const F& f) {
            int l = lca(u, v);
            for (auto&& [a, b] : ascend(u, l)) {
                int s = a + 1, t = b;
                s > t ? f(t, s) : f(s, t);
            }
            if (vertex) f(down[l], down[l] + 1);
            for (auto&& [a, b] : descend(l, v)) {
                int s = a, t = b + 1;
                s > t ? f(t, s) : f(s, t);
            }
        }

        template <typename F>
        //path_noncommutative_query(u, v, vertex, f): 非可換なパスクエリを処理する。O(log^2 N)
        void path_noncommutative_query(int u, int v, bool vertex, const F& f) {
            int l = lca(u, v);
            for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);
            if (vertex) f(down[l], down[l] + 1);
            for (auto&& [a, b] : descend(l, v)) f(a, b + 1);
        }

        template <typename F>
        //subtree_query(u, vertex, f): 部分木クエリを処理する。O(logN)
        void subtree_query(int u, bool vertex, const F& f) {
            f(down[u] + int(!vertex), up[u]);
        }

        //lca(u, v): uとvの最小共通祖先(LCA)を返す。O(logN)
        int lca(int a, int b) {
            while (nxt[a] != nxt[b]) {
                if (down[a] < down[b]) swap(a, b);
                a = par[nxt[a]];
            }
            return depth[a] < depth[b] ? a : b;
        }

        //dist(u, v): uとvのパスの距離(各辺の長さは1)を返す。O(logN)
        int dist(int a, int b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }
};

int main() {
    ll N;cin>>N;
    Graph G(N);
    vector<vector<ll>> edges(N-1);
    rep(i, N-1){
        ll a, b, c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        edges.at(i) = {a, b, c};
    }
    HeavyLightDecomposition<Graph> HL(G);
    auto siz = HL.idx(0).second;
    SegmentTree Z;
    Z.init(siz+1);
    rep(i, N-1){
        ll a = edges.at(i).at(0);
        ll b = edges.at(i).at(1);
        ll c = edges.at(i).at(2);
        if(HL.par.at(a) == b){
            swap(a,b);
        }
        Z.update(HL.idx(b).first, c);
    }
    ll Q;cin>>Q;
    vector<ll> ans_v;
    rep(i, Q){
        ll c, A, B;cin>>c>>A>>B;
        A--;
        if(c == 1){
            ll a = edges.at(A).at(0);
            ll b = edges.at(A).at(1);
            if(HL.par.at(a) == b){
                swap(a,b);
            }
            Z.update(HL.idx(b).first, B);
        }
        else{
            B--;
            ll ans = 0;
            auto f = [&](int u, int v){
                ans += Z.query(u, v);
            };
            HL.path_query(A, B, false, f);
            ans_v.push_back(ans);
        }
    }
    for(auto x:ans_v){
        out(x);
    }
}