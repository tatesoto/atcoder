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

// union by size + path having
class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
    ll cnt; //連結成分の個数

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL), cnt(sz_) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        cnt = 0;
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        cnt--;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }

    vector<vector<ll>> groups() {
        ll sz_ = par.size();
        vector<ll> par_buf(sz_), group_size(sz_);
        for (int i = 0; i < sz_; i++) {
            par_buf[i] = root(i);
            group_size[par_buf[i]]++;
        }
        std::vector<std::vector<ll>> result(sz_);
        for (int i = 0; i < sz_; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < sz_; i++) {
            result[par_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<ll>& v) { return v.empty(); }),
            result.end());
        return result;
    }
};

int main() {
    auto solve = [&](ll n, Graph G){
        return 1;
    };

    //愚直解かつ正しい解
    auto judge = [&](ll n, Graph G){
        vector<bool> used(n, false);
        auto dfs = [&](auto self, ll v, ll p)->void {
            used[v] = true;
            for(auto nv:G[v]){
                if(nv == p) continue;
                if(used[nv]) continue;
                self(self, nv, v);
            }
        };
        ll res = 0;
        rep(i, n){
            if(used[i]) continue;
            dfs(dfs, i, -1);
            res++;
        }
        return res;
    };

    //ランダムケース生成
    auto make_graph_test = [&](int i, bool is_tree = false, bool is_connected = true, bool is_directed = false, bool has_self_loop = false, bool has_multi_edge = false){
        uint64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
        mt19937_64 rnd(seed + i);

        uniform_int_distribution<int> dist_N(4, 10);
        ll n = dist_N(rnd);
        ll m;
        if(is_tree){
            m = n-1;
        }
        else if(is_connected){
            uniform_int_distribution<int> dist_M(n, n*(n-1)/2);
            m = dist_M(rnd);
        }
        else if(is_directed){
            uniform_int_distribution<int> dist_M(n, n*(n-1));
            m = dist_M(rnd);
        }
        else{
            uniform_int_distribution<int> dist_M(0, n*(n-1)/2);
            m = dist_M(rnd);
        }
        Graph G(n);
        UnionFind uf(n);
        set<pair<ll, ll>> st;
        auto generate_graph = [&]() {
            rep(j, m){
                uniform_int_distribution<int> dist_u(0, n-1);
                ll u = dist_u(rnd);
                uniform_int_distribution<int> dist_v(0, n-1);
                ll v = dist_v(rnd);
                if(!has_self_loop && u == v) {j--; continue;}
                if(!has_multi_edge){
                    if(is_directed){
                        if(st.count({u, v})){
                            j--;
                            continue;
                        }
                    }
                    else{
                        if(st.count({u, v}) || st.count({v, u})){
                            j--;
                            continue;
                        }
                    }
                }
                if(is_tree){
                    if(uf.issame(u, v)){
                        j--;
                        continue;
                    }
                    uf.merge(u, v);
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
                else if(is_directed){
                    G[u].push_back(v);
                }
                else{
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
                st.insert({u, v});
            }
        };

        auto is_connected_graph = [&](){
            vector<bool> used(n, false);
            auto dfs = [&](auto self, ll v)->void {
                used[v] = true;
                for(auto nv:G[v]){
                    if(used[nv]) continue;
                    self(self, nv);
                }
            };
            dfs(dfs, 0);
            rep(i, n){
                if(!used[i]) return false;
            }
            return true;
        };

        while(true){
            generate_graph();
            if(!is_connected) break;
            if(is_connected_graph()) break;
            G.clear();
            G.resize(n);
            st.clear();
            uf.init(n);
        }

        return make_pair(m, G);
    };

    //テスト
    auto test = [&](int i){
        auto T = make_graph_test(i); //単純無向グラフ
        // auto T = make_graph_test(i, true); //木
        // auto T = make_graph_test(i, false, false); //連結でない
        // auto T = make_graph_test(i, false, true, true); //有向
        // auto T = make_graph_test(i, false, false, false, true); //自己ループ
        // auto T = make_graph_test(i, false, false, false, false, true); //多重辺
        cout<<"input"<<endl;
        auto [m, G] = T;
        ll n = G.size();
        cout << n << " " << m << endl;
        rep(i, n){
            cout << G[i].size() << " ";
            for(auto nx:G[i]) cout << nx << " ";
            cout << endl;
        }
        auto p = solve(n, G);
        auto q = judge(n, G);

        cout<<"output"<<endl;
        out(p);
        if(p != q){
            out("expected: "<<q);
        }
    };
    
    rep(i, 10){
        cout<<"[test"<<i+1<<"]"<<endl;
        test(i);
        cout<<endl;
    }
}