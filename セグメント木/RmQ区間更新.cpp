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

class SegmentTree{
    public:
    //0-indexedで節点を管理する配列
    vector<ll> dat,lazy;
    ll siz=1;

    //初期化
    void init(ll N){
        //要素数を2のべき乗に
        siz=1;
        while(siz<N) siz*=2;
        //segment木の節点の数は、1+2+4+……+2^n=2^(n+1)-1 で求められる
        for(ll i=0;i<siz*2-1;i++){
            dat.push_back(INF);
            lazy.push_back(INF);
        }
    }

    //遅延評価
    //配列のk番目を更新
    void eval(ll k){
        if(lazy.at(k)==INF) return;
        if(k<siz-1){
            lazy.at(k*2+1)=lazy.at(k);
            lazy.at(k*2+2)=lazy.at(k);
        }
        dat.at(k)=lazy.at(k);
        lazy.at(k)=INF;
    }

    //[a,b)をxに更新する
    //kは今見ている節点の番号、l,rはその節点が[l,r)に対応していることを指す
    void __update(ll a,ll b,ll x,ll k,ll l,ll r){
        eval(k);
        //[a,b)が[l,r)を完全に含んでいれば、この節点以降すべてxに書き換える
        if(a<=l && r<=b){
            lazy.at(k)=x;
            eval(k);
        }
        //一部が交差していれば、2つの子について再帰する
        else if(a<r && l<b){
            __update(a,b,x,k*2+1,l,(l+r)/2);
            __update(a,b,x,k*2+2,(l+r)/2,r);
            dat.at(k)=min(dat.at(k*2+1),dat.at(k*2+2));
        }
    }

    void update(ll a,ll b,ll x){
        __update(a,b,x,0,0,siz);
    }

    //[a,b)の最小値を求める
    //kは今見ている節点の番号、l,rはその節点が[l,r)に対応していることを指す
    ll __query(ll a,ll b,ll k,ll l,ll r){
        eval(k);
        //[a,b)と[l,r)が交差しなければINFを返す
        if(r<=a||b<=l) return INF;
        //[a,b)が[l,r)を完全に含んでいれば、この節点の値
        if(a<=l && r<=b) return dat.at(k);
        //一部が交差していれば、2つの子の最小値を返す
        else{
            ll vl=__query(a,b,k*2+1,l,(l+r)/2);
            ll vr=__query(a,b,k*2+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }

    ll query(ll a,ll b){
        return __query(a,b,0,0,siz);
    }
};

int main() {
    //{3,1,4,1,5,9}について、[1,4)を10に置き換えて、[2,5)の最小値を求めてみる
    vector<ll> v={3,1,4,1,5,9};
    SegmentTree Z;
    Z.init(6);
    rep(i,6){
        Z.update(i,i+1,v.at(i));
    }
    Z.update(1,4,10);
    out(Z.query(2,5));
}