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

ll M;
ll modpow(const ll &a, ll n){
    if (n == 0) return 1;
    auto t = modpow(a, n / 2) % M;
    t = t * t % M;
    if (n & 1) t = t * a % M;
    return t % M;
}

int main() {
    ll N;cin>>N>>M;
    vector<ll> a(N);
    rep(i, N) cin>>a.at(i);
    vector<pair<ll, pair<ll,ll>>> edge;
    auto score = [&](ll i, ll j){
        return (modpow(i, j) + modpow(j, i))%M;
    };
    rep(i, N){
        for(int j = i+1;j<N;j++){
            edge.push_back({score(a.at(i), a.at(j)), {i, j}});
        }
    }
    sort(all(edge));
    reverse(all(edge));
    UnionFind uf(N);
    ll ans = 0;
    for(auto cp:edge){
        ll cost = cp.first;
        ll i = cp.second.first;
        ll j = cp.second.second;
        if(!uf.issame(i, j)){
            uf.merge(i, j);
            ans += cost;
        }
    }
    out(ans);
}