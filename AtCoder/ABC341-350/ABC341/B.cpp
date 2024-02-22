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
    vector<ll> A(N);
    rep(i, N) cin>>A[i];
    vector<pair<ll,ll>> st(N-1);
    rep(i, N-1) {
        ll s, t;cin>>s>>t;
        st[i] = {s, t};
    }
    rep(i, N-1) {
        auto [s, t] = st[i];
        ll c = A[i]/s;
        A[i] -= c*s;
        A[i+1] += c*t;
    }
    out(A[N-1]);
}