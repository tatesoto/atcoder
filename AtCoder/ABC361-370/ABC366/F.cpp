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
    vector<pair<ll, ll>> f(N);
    rep(i, N) {
        cin>>f[i].first>>f[i].second;
    }
    sort(all(f), [](pair<ll, ll> a, pair<ll, ll> b) {
        if (a.first + a.second == b.first + b.second) {
            return a.first < b.first;
        }
        return a.first + a.second < b.first + b.second;
    });
    reverse(all(f));
    ll ans = 1;
    for (int i = K-1; i >= 0; i--) {
        ans = f[i].first * ans + f[i].second;
    }
    out(ans);
}
