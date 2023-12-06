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

//※RUQ……Range add Query

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
            dat.push_back(-INF);
            lazy.push_back(0);
        }
    }

    //pos番目の値(0-indexed)をxに変更する
    void update(ll pos,ll x){
        pos=pos+siz-1;
        dat.at(pos)=x;
        while(pos>0){
            pos=(pos-1)/2;
            dat.at(pos)=max(dat.at(pos*2+1),dat.at(pos*2+2));
        }
    }

    //遅延評価
    //配列のk番目を更新
    void eval(ll k){
        if(lazy.at(k)==0) return;
        if(k<siz-1){
            lazy.at(k*2+1)+=lazy.at(k)/2;
            lazy.at(k*2+2)+=lazy.at(k)/2;
        }
        dat.at(k)+=lazy.at(k);
        lazy.at(k)=0;
    }

    //[a,b)をxに更新する
    //kは今見ている節点の番号、l,rはその節点が[l,r)に対応していることを指す
    void __add(ll a,ll b,ll x,ll k,ll l,ll r){
        eval(k);
        //[a,b)が[l,r)を完全に含んでいれば、この節点以降すべてxに書き換える
        if(a<=l && r<=b){
            lazy.at(k)+=(r-l)*x;
            eval(k);
        }
        //一部が交差していれば、2つの子について再帰する
        else if(a<r && l<b){
            __add(a,b,x,k*2+1,l,(l+r)/2);
            __add(a,b,x,k*2+2,(l+r)/2,r);
            dat.at(k)=dat.at(k*2+1)+dat.at(k*2+2);
        }
    }

    void add(ll a,ll b,ll x){
        __add(a,b,x,0,0,siz);
    }

    //[a,b)の最大値を求める
    //kは今見ている節点の番号、l,rはその節点が[l,r)に対応していることを指す
    ll __query(ll a,ll b,ll k,ll l,ll r){
        eval(k);
        //[a,b)と[l,r)が交差しなければ-INFを返す
        if(r<=a||b<=l) return -INF;
        //[a,b)が[l,r)を完全に含んでいれば、この節点の値
        if(a<=l && r<=b) return dat.at(k);
        //一部が交差していれば、2つの子の最大値を返す
        else{
            ll vl=__query(a,b,k*2+1,l,(l+r)/2);
            ll vr=__query(a,b,k*2+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }

    ll query(ll a,ll b){
        return __query(a,b,0,0,siz);
    }
};

int main() {
    //{3,1,4,1,5,9}について、[1,4)に5を足して、[2,5)の最大値を求めてみる
    vector<ll> v={3,1,4,1,5,9};
    SegmentTree Z;
    Z.init(6);
    rep(i,6){
        Z.update(i,v.at(i));
    }
    Z.add(1,4,5);
    out(Z.query(2,5));
}