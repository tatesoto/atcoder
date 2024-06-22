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

int main() {
    ll A, B, C, D;cin>>A>>B>>C>>D;
    A += 1e9 + 100;
    B += 1e9 + 100;
    C += 1e9 + 100;
    D += 1e9 + 100;

    auto area = [&] (ll x, ll y) {
        ll res = 0;
        ll qx = x /4;
        ll rx = x % 4;
        ll qy = y / 2;
        ll ry = y % 2;
        if(ry == 0) {
            res += 8*qy*qx;
            if(rx >= 1) res += 3*qy;
            if(rx >= 2) res += 3*qy;
            if(rx >= 3) res += qy;
        } else {
            res += (8*qy+4)*qx;
            if(rx >= 1) res += 3*qy+2;
            if(rx >= 2) res += 3*qy+1;
            if(rx >= 3) res += qy;
        }
        return res;
    };

    ll ans = area(C, D) - area(A, D) - area(C, B) + area(A, B);
    out(ans);
}