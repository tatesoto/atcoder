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

// modint: mod 計算を int を扱うように扱える構造体
// From: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
const int MOD = mod;
using mint = Fp<MOD>;


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
    ll N;cin>>N;
    vector<pair<ll,ll>> vp(N-1);
    vector<ll> lastMatch(N);
    vector<vector<pair<ll,mint>>> G(2*N-1);
    vector<ll> nodesiz(2*N-1, 1);
    rep(i, N){
        G[i].push_back({-1, 0});
    }
    UnionFind uf(N);
    rep(i, N){
        lastMatch.at(i) = i;
    }
    rep(i, N-1){
        ll p, q;cin>>p>>q;p--;q--;
        ll rootp = uf.root(p);
        ll rootq = uf.root(q);
        ll pnode = lastMatch[rootp];
        ll qnode = lastMatch[rootq];
        ll pnode_siz = nodesiz.at(pnode);
        ll qnode_siz = nodesiz.at(qnode);
        mint pweight = mint(pnode_siz)/mint(pnode_siz+qnode_siz);
        mint qweight = mint(qnode_siz)/mint(pnode_siz+qnode_siz);
        G[N+i].push_back({pnode, pweight});
        G[N+i].push_back({qnode, qweight});
        uf.merge(p, q);
        ll rootpq = uf.root(p);
        nodesiz.at(N+i) = nodesiz.at(pnode) + nodesiz.at(qnode); 
        lastMatch.at(rootpq) = N+i;
    }
    vector<mint> dist(2*N-1, 0);
    queue<ll> q;
    q.push(2*N-2);
    while(!q.empty()){
        auto pos = q.front();q.pop();
        for(auto np:G[pos]){
            auto [next, w] = np;
            if(next < 0) continue;
            dist.at(next) = dist.at(pos) + w;
            q.push(next);
        }
    }
    rep(i, N){
        out(dist.at(i));
    }
}
