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
    ll T;cin>>T;
    string S;cin>>S;
    vector<ll> right;
    vector<ll> left;
    rep(i, N) {
        ll x;cin>>x;
        if(S[i] == '0') {
            left.push_back(x);
        }
        if(S[i] == '1') {
            right.push_back(x);
        }
    }
    auto lower_count = [&](vector<ll> &v, ll x) {
        return lower_bound(all(v), x) - v.begin();
    };
    auto range_count = [&](vector<ll> &v, ll l, ll r) {
        return lower_count(v, r) - lower_count(v, l);
    };
    sort(all(left));
    sort(all(right));
    ll ans = 0;
    for(auto x : right) {
        ans += range_count(left, x, x + 2*T + 1);
    }
    out(ans);
}