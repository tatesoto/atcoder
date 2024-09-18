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
    rep(i, N) cin>>A[i];
    vector<ll> sum(2*N+1, 0);
    rep(i, 2*N) sum[i+1] = sum[i] + A[i%N];
    vector<ll> cnt(M, 0);
    for (int i = 1; i < N; i++) {
        cnt[sum[i]%M]++;
    }
    ll ans = 0;
    ll now = 0;
    rep(i, N) {
        ans += cnt[now%M];
        now += A[i];
        now %= M;
        cnt[sum[i+1]%M]--;
        cnt[(sum[i+N])%M]++;
    }
    out(ans);
}
