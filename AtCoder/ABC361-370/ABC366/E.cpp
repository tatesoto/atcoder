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
    ll N, D;cin>>N>>D;
    vector<ll> X(N), Y(N);
    rep(i, N) {
        cin>>X[i]>>Y[i];
    }
    sort(all(X));
    sort(all(Y));
    vector<ll> sum_x(N+1), sum_y(N+1);
    rep(i, N) {
        sum_x[i+1] = sum_x[i] + X[i];
        sum_y[i+1] = sum_y[i] + Y[i];
    }
    auto get_xsum = [&](ll l, ll r) {
        return sum_x[r] - sum_x[l];
    };
    auto get_ysum = [&](ll l, ll r) {
        return sum_y[r] - sum_y[l];
    };
    auto manhattan_xsum = [&] (ll x) {
        ll id = lower_bound(all(X), x) - X.begin();
        ll res = 0;
        res += x * id - get_xsum(0, id);
        res += get_xsum(id, N) - x * (N - id);
        return res;
    };
    auto manhattan_ysum = [&] (ll x) {
        ll id = lower_bound(all(Y), x) - Y.begin();
        ll res = 0;
        res += x * id - get_ysum(0, id);
        res += get_ysum(id, N) - x * (N - id);
        return res;
    };
    vector<ll> x_dist(D+1, 0), y_dist(D+1, 0);
    for (ll i = -2*1000000; i <= 2*1000000; i++) {
        ll xd = manhattan_xsum(i);
        if(xd <= D) {
            x_dist[xd]++;
        }
        ll yd = manhattan_ysum(i);
        if(yd <= D) {
            y_dist[yd]++;
        }
    }
    vector<ll> y_dist_sum(D+2, 0);
    rep(i, D+1) {
        y_dist_sum[i+1] = y_dist_sum[i] + y_dist[i];
    }
    auto get_y_dist_sum = [&](ll l, ll r) {
        return y_dist_sum[r] - y_dist_sum[l];
    };
    ll ans = 0;
    for (ll i = 0; i <= D; i++) {
        ans += x_dist[i] * get_y_dist_sum(0LL, D-i+1);
    }
    out(ans);
}
