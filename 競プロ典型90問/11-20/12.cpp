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

ll H,W;
ll change(ll x,ll y){
    return W*(x-1)+y-1;
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
    cin>>H>>W;
    UnionFind uf(H*W);
    vector<bool> red(H*W,false);
    vector<ll> dx={1,0,-1,0};
    vector<ll> dy={0,1,0,-1};
    ll Q;cin>>Q;
    rep(i,Q){
        ll q;cin>>q;
        if(q==1){
            ll r,c;cin>>r>>c;
            ll x=change(r,c);
            red.at(x)=true;
            for(ll i=0;i<4;i++){
                ll R=r+dx.at(i);
                ll C=c+dy.at(i);
                if(R<=0||C<=0||R>H||C>W) continue;
                ll y=change(R,C);
                if(red.at(y)){
                    uf.merge(x,y);
                }
            }
        }
        else{
            ll a,b,c,d;cin>>a>>b>>c>>d;
            ll x=change(a,b);
            ll y=change(c,d);
            if(uf.issame(x,y)&&red.at(x)){
                out("Yes");
            }
            else{
                out("No");
            }
        }
    }
}