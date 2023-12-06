#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;

//座標圧縮、計算量はNlogN、0-indexed;
vector<ll> Scompression(vector<string> v){
    vector<string> T;
    vector<ll> ans;
    rep(i,v.size()){
        T.push_back(v.at(i));
    }
    sort(all(T));
    T.erase(unique(all(T)),T.end());
    rep(i,v.size()){
        ll x=lower_bound(all(T),v.at(i))-T.begin();
        ans.push_back(x);
        //1-indexed
        // ans.at(i)++;
    }
    return ans;
}

// union by size + path having
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
};

int main() {
    ll N;cin>>N;
    vector<string> s(2*N);
    rep(i,N){
        cin>>s.at(i)>>s.at(i+N);
    }
    vector<ll> snum;
    snum = Scompression(s);
    UnionFind uf(2*N);
    rep(i,N){
        if(uf.issame(snum.at(i),snum.at(i+N))){
            out("No");
            return 0;
        }
        uf.merge(snum.at(i),snum.at(i+N));
    }
    out("Yes");
}