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
    ll N, X, Y;cin>>N>>X>>Y;
    vector<ll> A(N), B(N);
    rep(i, N) cin>>A[i];
    rep(i, N) cin>>B[i];
    sort(all(A));
    reverse(all(A));
    ll ans = 0;
    ll nowx = 0;
    rep(i, N) {
        nowx += A[i];
        ans++;
        if(nowx > X) {
            break;
        }
    }
    sort(all(B));
    reverse(all(B));
    ll res = 0;
    ll nowy = 0;
    rep(i, N) {
        nowy += B[i];
        res++;
        if(nowy > Y) {
            break;
        }
    }
    chmin(ans, res);
    out(ans);
}