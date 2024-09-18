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
    A.push_back(INF);
    ll ans = 0;
    ll l = 0;
    ll r = 0;
    while(l < N) {
        while(r < N && (r == l || A[r+1] - A[r] == A[r] - A[r-1])) r++;
        ll n = r - l + 1;
        ans += n * (n - 1) / 2;
        l = r;
    }
    out(ans + N - 1);
}
