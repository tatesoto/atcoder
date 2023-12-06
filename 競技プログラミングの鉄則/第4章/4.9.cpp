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
            dat.at(pos)=max(dat.at(pos*2+1),dat.at(pos*2+2));
        }
    }

    //[a,b)の最大値を求める
    //kは今見ている節点の番号、l,rはその節点が[l,r)に対応していることを指す
    ll __query(ll a,ll b,ll k,ll l,ll r){
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
//座標圧縮、計算量はNlogN;
vector<ll> compression(vector<ll> v){
    vector<ll> T,ans;
    rep(i,v.size()){
        T.push_back(v.at(i));
    }
    sort(all(T));
    T.erase(unique(all(T)),T.end());
    rep(i,v.size()){
        ll x=lower_bound(all(T),v.at(i))-T.begin();
        ans.push_back(x);
        ans.at(i)++;
    }
    return ans;
}


int main() {
    ll N;cin>>N;
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    a=compression(a);
    SegmentTree dp;
    dp.init(N+2);
    rep(i,N){
        ll p=a.at(i);
        ll M=dp.query(0,p);
        dp.update(p,M+1);
    }
    out(dp.query(0,N+1));
}