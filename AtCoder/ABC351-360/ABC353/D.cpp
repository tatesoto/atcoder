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

int main() {
    ll N;cin>>N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    auto get_digit=[](ll x) {
        ll res=0;
        while(x) {
            x/=10;
            res++;
        }
        return res;
    };
    vector<ll> digit_A(N);
    vector<ll> sum(N+1, 0);
    rep(i,N) {
        sum[i+1]=sum[i]+A[i];
        sum[i+1]%=MOD;
    }
    auto get_sum=[&](ll l, ll r) {
        return sum[r]-sum[l];
    };
    rep(i,N) digit_A[i]=get_digit(A[i]);
    vector<ll> ten_pow_by_digit(N);
    rep(i, N) {
        ten_pow_by_digit[i]=1;
        rep(j, digit_A[i]) {
            ten_pow_by_digit[i]*=10;
            ten_pow_by_digit[i]%=MOD;
        }
    }
    vector<ll> ten_pow_by_digit_sum(N+1);
    rep(i, N) {
        ten_pow_by_digit_sum[i+1]=ten_pow_by_digit_sum[i]+ten_pow_by_digit[i];
        ten_pow_by_digit_sum[i+1]%=MOD;
    }
    auto get_ten_pow_by_digit_sum=[&](ll l, ll r) {
        return ten_pow_by_digit_sum[r]-ten_pow_by_digit_sum[l];
    };
    mint ans=0;
    rep(i, N) {
        ll tmp=0;
        tmp+=get_ten_pow_by_digit_sum(i+1, N);
        tmp*=A[i];
        tmp%=MOD;
        tmp+=get_sum(i+1, N);
        tmp%=MOD;
        ans+=tmp;
    }
    out(ans);
}