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
    auto isLine = [&](pair<ll,ll> p1, pair<ll,ll> p2, pair<ll,ll> p3) -> bool {
        auto [x1, y1] = p1;
        auto [x2, y2] = p2;
        auto [x3, y3] = p3;
        return (x1 - x2) * (y1 - y3) == (x1 - x3) * (y1 - y2);

    };
    vector<pair<ll,ll>> P(N);
    rep(i, N) {
        ll x, y;cin>>x>>y;
        P[i] = {x, y};
    }
    rep(i, N) {
        rep(j, i) {
            rep(k, j) {
                if(isLine(P[i], P[j], P[k])) {
                    out("Yes");
                    return 0;
                }
            }
        }
    }
    out("No");
}
