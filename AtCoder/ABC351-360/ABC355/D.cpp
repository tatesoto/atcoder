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
    vector<pair<ll,ll>> A;
    rep(i, N) {
        ll l, r;cin>>l>>r;
        A.push_back({l, -1});
        A.push_back({r, 1});
    }
    sort(all(A), [](const pair<ll,ll> &a, const pair<ll,ll> &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    ll ans = 0;
    ll active_intervals = 0;
    for(auto &a : A) {
        if(a.second == -1) {
            ans += active_intervals;
            active_intervals++;
        } else {
            active_intervals--;
        }
    }
    out(ans);
}