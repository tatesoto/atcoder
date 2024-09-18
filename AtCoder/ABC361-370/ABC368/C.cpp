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
    ll N;cin>>N;
    vector<ll> H(N);
    rep(i, N) cin>>H[i];
    auto damage = [&] (ll t, ll p) {
        ll q = t/3;
        ll r = t%3;
        vector<ll> A;
        if (p == 0) {
            A = {1, 1, 3};
        }
        else if (p == 1) {
            A = {1, 3, 1};
        }
        else {
            A = {3, 1, 1};
        }
        ll res = 0;
        res += q * 5;
        rep(i, r) {
            res += A[i];
        }
        return res;
    };
    ll T = 0;
    rep(i, N) {
        ll left = 0;
        ll right = 1e12;
        while(right - left > 1) {
            ll mid = (left + right) / 2;
            if (damage(mid, T%3) < H[i]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        T += right;
    }
    out(T);
}
