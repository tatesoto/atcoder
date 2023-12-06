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

int N;

//dp[i]......i番目まで見たときのLISの長さ
vector<ll> LIS(vector<ll> A){
    vector<ll> dp(N);
    SegmentTree Z;
    Z.init(N+1);
    rep(i, N+1){
        Z.update(i, 0);
    }
    rep(i, N){
        ll MaxLength = Z.query(0, A.at(i));
        ll now = Z.query(A.at(i), A.at(i)+1);
        Z.update(A.at(i), max(now, MaxLength + 1));
        dp.at(i) = Z.query(0, N+1);
    }
    return dp;
}

int main() {
    cin>>N;
    vector<ll> A(N);
    rep(i, N) cin>>A.at(i);
    vector<ll> dp, rdp;
    dp = LIS(A);
}