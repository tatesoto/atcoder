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

// modint: mod 計算を int を扱うように扱える構造体
// From: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
const int MOD = mod;
using mint = Fp<MOD>;

class SegmentTree{
    public:
    //0-indexedで節点を管理する配列
    vector<mint> dat;
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
    void update(ll pos,mint x){
        pos=pos+siz-1;
        dat.at(pos)=x;
        while(pos>0){
            pos=(pos-1)/2;
            dat.at(pos)=dat.at(pos*2+1)+dat.at(pos*2+2);
        }
    }

    //[a,b)の区間和を求める
    //kは今見ている節点の番号、l,rはその節点が[l,r)に対応していることを指す
    mint __query(ll a,ll b,ll k,ll l,ll r){
        //[a,b)と[l,r)が交差しなければINFを返す
        if(r<=a||b<=l) return 0;
        //[a,b)が[l,r)を完全に含んでいれば、この節点の値
        if(a<=l && r<=b) return dat.at(k);
        //一部が交差していれば、2つの子の最小値を返す
        else{
            mint vl=__query(a,b,k*2+1,l,(l+r)/2);
            mint vr=__query(a,b,k*2+2,(l+r)/2,r);
            return vl+vr;
        }
    }

    mint query(ll a,ll b){
        if (a >= b) return 0;
        return __query(a,b,0,0,siz);
    }
};

int main() {
    ll N, K;cin>>N>>K;
    vector<ll> A(N);
    rep(i, N) cin>>A[i];
    SegmentTree dp;
    dp.init(N+1);
    dp.update(N, 1);
    vector<ll> sum(N+1, 0);
    rep(i, N) {
        sum[i+1] = sum[i] + A[i];
    }
    auto get_sum = [&](ll l, ll r) {
        if (r > N) return INF;
        return sum[r] - sum[l];
    };
    auto get_sum_K_indices = [&](ll l, ll r) {
        pair<ll, ll> res;
        ll ok = r, ng = l;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;
            if (get_sum(l, mid) >= K) {
                ok = mid;
            }
            else {
                ng = mid;
            }
        }
        if(get_sum(l, ok) != K) return make_pair(0LL, 0LL);
        res.first = ok-1;
        ok = l, ng = r+1;
        while (ng-ok > 1) {
            ll mid = (ok + ng) / 2;
            if (get_sum(l, mid) <= K) {
                ok = mid;
            }
            else {
                ng = mid;
            }
        }
        res.second = ok;
        return res;
    };
    for (int i = N-1; i >= 0; i--) {
        pair<ll, ll> indices = get_sum_K_indices(i, N);
        mint x = dp.query(i, N+1);
        mint y = dp.query(indices.first+1, indices.second);
        if(indices.second == N) y += 1;
        dp.update(i, x-y);
    }
    out(dp.query(0, 1));
}
