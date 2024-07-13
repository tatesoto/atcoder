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
    vector<pair<ll,ll>> point(3);
    rep(i, 3) cin>>point[i].first>>point[i].second;
    auto is_right_triangle = [&](pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c) {
        pair<ll,ll> ab = {b.first - a.first, b.second - a.second};
        pair<ll,ll> ac = {c.first - a.first, c.second - a.second};
        if(ab.first == 0 && ab.second == 0) return false;
        if(ac.first == 0 && ac.second == 0) return false;
        return ab.first *ac.first + ab.second * ac.second == 0;
    };
    rep(i, 3) {
        if(is_right_triangle(point[i], point[(i + 1) % 3], point[(i + 2) % 3])) {
            out("Yes");
            return 0;
        }
    }
    out("No");
}