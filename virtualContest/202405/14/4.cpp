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
    ll N, Q;cin>>N>>Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));
    vector<ll> X(Q);
    rep(i, Q) cin>>X[i];
    vector<ll> sum(N+1, 0);
    rep(i, N) sum[i+1] = A[i] + sum[i];
    auto get_sum = [&](ll l, ll r) {
        return sum[r] - sum[l];
    };
    auto query = [&] (ll x) {
        ll id = lower_bound(all(A), x) - A.begin();
        ll res = (2*id-N) *x;
        res -= get_sum(0, id);
        res += get_sum(id, N);
        return res;
    };
    rep(i, Q) out(query(X[i]));
}
