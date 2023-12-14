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
    sort(all(A));
    sort(all(B));
    vector<ll> sumB(M+1, 0);
    rep(i, M) sumB[i+1] = sumB[i] + B[i];
    ll ans = 0;
    rep(i, N){
        ll a = A[i];
        ll b = P - a;
        ll k = distance(B.begin(), lower_bound(all(B), b));
        ans += k * a + sumB[k] + (M-k) * P;
    }
    out(ans);
}
