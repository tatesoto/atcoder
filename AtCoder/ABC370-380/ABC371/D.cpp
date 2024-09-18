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
    vector<pair<ll,ll>> X(N);
    rep(i, N) {
        ll x;cin>>x;
        X[i] = {x, i};
    }
    X.push_back({INF, N});
    vector<ll> P(N);
    rep(i, N) cin>>P[i];
    ll Q;cin>>Q;
    vector<ll> L(Q), R(Q);
    rep(i, Q) cin>>L[i]>>R[i], R[i]++;
    vector<ll> A(N+1, 0);
    rep(i, N) {
        A[i+1] = A[i] + P[i];
    }
    auto query = [&](ll l, ll r) {
        auto it = lower_bound(all(X), make_pair(l, -1LL));
        ll id = it->second;
        auto it2 = lower_bound(all(X), make_pair(r, -1LL));
        ll id2 = it2->second;
        out(A[id2] - A[id]);
        return;
    };
    rep(i, Q) {
        query(L[i], R[i]);
    }

}
