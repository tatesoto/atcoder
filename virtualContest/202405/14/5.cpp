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
    ll N, K;cin>>N>>K;
    vector<ll> xp, xm;
    rep(i, N) {
        ll x;cin>>x;
        if(x < 0) xm.push_back(-x);
        else xp.push_back(x);
    }
    sort(all(xm));
    auto time = [&](ll m, ll p) {
        if(p > xp.size() || m > xm.size()) return INF;
        ll l = (m > 0) ? xm[m-1] : 0;
        ll r = (p > 0) ? xp[p-1] : 0;
        return l + r + min(l, r);
    };

    ll ans = INF;
    for(int i = 0; i <= K; i++) {
        chmin(ans, time(i, K-i));
    }
    out(ans);
}
