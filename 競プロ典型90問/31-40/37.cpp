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
        for(ll i=0;i<siz*2-1;i++) dat.push_back(-INF);
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

int main() {
    ll W, N;cin>>W>>N;
    vector<ll> l(N), r(N), v(N);
    rep(i, N) cin >> l.at(i) >> r.at(i) >> v.at(i);
    vector<vector<ll>> dp(N+1, vector<ll>(W+1, -INF));
    SegmentTree Z;
    Z.init(W+1);
    dp.at(0).at(0) = 0;
    rep(i, N){
        rep(j, W+1){
            Z.update(j, dp.at(i).at(j));
        }
        rep(j, W+1){
            chmax(dp.at(i+1).at(j), dp.at(i).at(j));
            ll M = Z.query(max(0LL, j-r.at(i)), max(0LL, j-l.at(i)+1));
            chmax(dp.at(i+1).at(j), M + v.at(i));
        }
    }
    // rep(i, N+1){
    //     rep(j, W+1){
    //         cout<<dp.at(i).at(j)<<" ";
    //     }
    //     cout<<"\n";
    // }
    out(max(-1LL, dp.at(N).at(W)));
}