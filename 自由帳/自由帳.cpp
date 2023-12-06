#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull uint64_t
#define pll pair<ll,ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vvvll vector<vvll>
#define vpll vector<pll>
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
#define vvv(T) vector<vector<vector<T>>>
// template<class T> struct v : vector<T> { using vector<T> :: vector; };
// template<class T> struct vv : vector<v<T>> { using vector<v<T>> :: vector; };
// template<class T> struct vvv : vector<vv<T>> { using vector<vv<T>> :: vector; };
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i,n) for(ll i = (ll)(n - 1); i >= 0; i--)
#define REP(i, l, r) for(ll i = (ll)l; i <= (ll)(r); i++)
#define REPR(i, l, r) for(ll i = (ll)r; i >= (ll)(l); i--)
const ll inf = (1 << 30);
const ll INF = ((ll)1 << 60);
template<class T> void out(T a){cout << a << endl;}
template<class T> void out1(T a){cout << a;}
template<class T, class U> void out2(T a, U b){cout << a << " " << b << endl;}
template<class T, class U, class V> void out3(T a, U b, V c) {cout << a << " " << b << " " << c << endl;}
template<class T> void outv(T a){rep(i, a.size()){ cout << a.at(i) << " "; } cout << endl;}
template<class T> void outvmint(T a) {rep(i, a.size()) { cout << a.at(i).val() << " "; } cout << endl;}
template<class T> void outvL(T a){rep(i, a.size()){out(a.at(i));}}
template<class T> void outvLmint(T a) {rep(i, a.size()){out(a.at(i).val());}}
template<class T> void outvv(T a){rep(i, a.size()){ rep(j, a.at(i).size()){cout << a.at(i).at(j) << " "; } cout << endl; }}
template<class T> void outvp(T a){rep(i, a.size()){ out2(a.at(i).first, a.at(i).second); }}
template<class T> void setpre(T a){cout << fixed << setprecision(a);}
#define outN out("No")
#define outY out("Yes")
#define outL cout << endl
#define dame return 0
#define All(a) (a).begin(), (a).end()
template<class T> inline void sortr(T& v){sort(All(v)); reverse(All(v));};
ll powll(ll x, ll n){ll ret = 1; while(n > 0){if(n & 1) ret *= x; x *= x; n >>= 1;} return ret;}
#define cin1(n) cin >> (n)
#define cin2(n, m) cin >> (n) >> (m)
#define cin3(n, m, k) cin >> (n) >> (m) >> (k)
#define cinv(a) rep(lopi, a.size()) cin >> (a).at(lopi)
#define cinll1(n) ll n; cin >> (n)
#define cinll2(n, m) ll n, m; cin >> (n) >> (m)
#define cinll3(n, m, k) ll n, m, k; cin >> (n) >> (m) >> (k)
#define cinvll(a, n) vll a(n); rep(lopi, (n)) cin >> (a).at(lopi)
#define cinvt(type, a, n) v(type) a(n); rep(lopi, n) cin >> (a).at(lopi)
#define makeundirGll(G, N, M) rep(lopi, M) {ll a, b; cin >> a >> b; G.at(a-1).push_back(b-1); G.at(b-1).push_back(a-1);}
#define makedirGll(G, N, M) rep(lopi, M) {ll a, b; cin >> a >> b; G.at(a-1).push_back(b-1);}
#define makeundirwghGll(G, N, M) rep(lopi, M) {ll a, b, c; cin >> a >> b >> c; G.at(a-1).push_back({b-1,c}); G.at(b-1).push_back({a-1, c});}
#define makedirwghGll (G, N, M) rep(lopi, M) {ll a, b, c; cin >> a >> b >> c; G.at(a-1).push_back({b-1, c});}
ll llceil(ll x, ll y) { if(x >= 0) {return(x / y + (ll)(x % y != 0)); } else { return -((-x) / y); } }

int main()
{   
    ll ans = 0;
    for(int n = 1; n<=512;n++){
        ll cnt = 0;
        for(int a = 1; a <= 2000;a++){
            for(int b = 1; b <= 2000; b++){
                if(a*b - a*a + b == n) cnt++;
            }
        }
        if(cnt == 1) ans++;
    }
    out(ans);
}