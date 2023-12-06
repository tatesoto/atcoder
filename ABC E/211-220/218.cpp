#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
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
    ll N,M;cin>>N>>M;
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    rep(i, M){
        ll a, b, c;cin>>a>>b>>c;
        a--;b--;
        pq.push({c, {a, b}});
    }
    UnionFind uf(N);
    ll reward = 0;
    rep(i, M){
        auto edge = pq.top();pq.pop();
        ll weight = edge.first;
        auto p = edge.second;
        ll a = p.first, b = p.second;
        if(uf.issame(a, b)) reward += max(0LL, weight);
        else uf.merge(a, b);
    }
    out(reward);
}