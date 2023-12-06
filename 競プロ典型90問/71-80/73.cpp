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
const int MOD = 1e9 + 7;
using mint = Fp<MOD>;

//行きがけ、通りがけ、帰りがけのすべてを記録
Graph G;
vector<vector<mint>> dp;
vector<char> c;

void dfs(ll s, ll p){
    mint res1 = 1;
    mint res2 = 1;
    for(auto next:G[s]){
        if(next != p){
            dfs(next, s);
            if(c.at(s) == 'a'){
                res1 *= (dp.at(next).at(0) + dp.at(next).at(2));
            }
            if(c.at(s) == 'b'){
                res1 *= (dp.at(next).at(1) + dp.at(next).at(2));
            }
            res2 *= (mint(2)*dp.at(next).at(2) + dp.at(next).at(0) + dp.at(next).at(1));
        }
    }
    if(c.at(s) == 'a'){
        dp.at(s).at(0) = res1;
        dp.at(s).at(2) = res2 - res1;
    }
    else{
        dp.at(s).at(1) = res1;
        dp.at(s).at(2) = res2 - res1;
    }
    return;
}

int main() {
    ll N;cin>>N;
    G.resize(N);
    c.resize(N);
    rep(i, N) cin>>c.at(i);
    rep(i, N-1){
        ll a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dp.resize(N, vector<mint>(3, 0));
    dfs(0, -1);
    out(dp.at(0).at(2));
}