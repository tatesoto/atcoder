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
    ll N, M, P;cin>>N>>M>>P;
    vector<ll> A(N), B(M);
    rep(i, N) cin>>A[i];
    rep(i, M) cin>>B[i];
    sort(all(B));
    ll ans = 0;
    vector<ll> sum(M+1, 0);
    rep(i, M) sum[i+1] = sum[i] + B[i];
    rep(i, N){
        ll d = distance(B.begin(), lower_bound(all(B), P-A[i]));
        ll n = M - d;
        ans += A[i]*d + sum[d] + P*n;
    } 
    out(ans);
}