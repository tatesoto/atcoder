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
    ll N, M;cin>>N>>M;
    vector<ll> A(N);
    rep(i, N) {
        cin>>A[i];
    }
    sort(all(A));
    vector<ll> sum(N+1, 0);
    rep(i, N) {
        sum[i+1] = sum[i] + A[i];
    }
    auto range_sum = [&] (ll l, ll r) {
        return sum[r] - sum[l];
    };
    auto judge = [&](ll x) {
        ll res = 0;
        auto iter = lower_bound(all(A), x);
        ll id = distance(A.begin(), iter);
        res += x * (N - id) + range_sum(0, id);
        return res <= M;
    };
    ll ok = 0, ng = 1e11;
    while(ng-ok > 1) {
        ll mid = (ok + ng) / 2;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    if(ok >= 1e10) out("infinite");
    else out(ok);
    
}