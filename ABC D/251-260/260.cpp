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
    ll N,K;cin>>N>>K;
    UnionFind uf(N+1);
    vector<ll> p(N+1);
    vector<ll> b(N+1,-1);
    vector<ll> ans(N+1,-1);
    set<ll> s;
    for(ll i=1;i<=N;i++){
        cin>>p.at(i);
    }
    for(ll i=1;i<=N;i++){
        ll X=p.at(i);
        auto iter=s.lower_bound(X);
        if(iter==s.end()){
            s.insert(X);
            if(uf.size(X)==K){
                s.erase(X);
                ll z=X;
                while(true){
                    ans.at(z)=i;
                    if(b.at(z)==-1){
                        break;
                    }
                    else{
                        z=b.at(z);
                    }
                }
            }
        }
        else{
            ll y=*iter;
            s.insert(X);
            s.erase(y);
            b.at(X)=y;
            uf.merge(X,y);
            if(uf.size(X)==K){
                s.erase(X);
                ll z=X;
                while(true){
                    ans.at(z)=i;
                    if(b.at(z)==-1){
                        break;
                    }
                    else{
                        z=b.at(z);
                    }
                }
            }
        }
    }
    for(ll i=1;i<=N;i++){
        out(ans.at(i));
    }
}