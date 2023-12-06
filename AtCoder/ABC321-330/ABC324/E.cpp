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
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

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
            dat.at(pos)=dat.at(pos*2+1)+dat.at(pos*2+2);
        }
    }

    //[a,b)の区間和を求める
    //kは今見ている節点の番号、l,rはその節点が[l,r)に対応していることを指す
    ll __query(ll a,ll b,ll k,ll l,ll r){
        //[a,b)と[l,r)が交差しなければINFを返す
        if(r<=a||b<=l) return 0;
        //[a,b)が[l,r)を完全に含んでいれば、この節点の値
        if(a<=l && r<=b) return dat.at(k);
        //一部が交差していれば、2つの子の最小値を返す
        else{
            ll vl=__query(a,b,k*2+1,l,(l+r)/2);
            ll vr=__query(a,b,k*2+2,(l+r)/2,r);
            return vl+vr;
        }
    }

    ll query(ll a,ll b){
        return __query(a,b,0,0,siz);
    }
};

int main() {
    ll N;cin>>N;
    string T;cin>>T;
    vector<string> S(N);
    rep(i, N) cin>>S[i];
    map<ll,ll> fro;
    SegmentTree Z;
    Z.init(T.size() +1);
    rep(i, N){
        ll n = S[i].size();
        ll nid = 0;
        rep(j, n){
            if(S[i][j] == T[nid]){
                nid++;
                if(nid == T.size()) break;
            }
        }
        fro[nid]++;
        ll cnt = 0;
        nid = T.size()-1;
        for(int j = n-1; j >= 0; j--){
            if(S[i][j] == T[nid]){
                nid--;
                cnt++;
                if(nid == -1) break;
            }
        }
        ll m = Z.query(cnt, cnt+1);
        Z.update(cnt, m+1);
    }

    ll ans = 0;
    for(auto p:fro){
        auto [n, c] = p;
        ans += c*Z.query(T.size()-n, T.size()+1);
    }
    out(ans);
}