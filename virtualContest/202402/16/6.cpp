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
    vector<ll> A(M);
    rep(i, M) cin>>A[i], A[i]--;
    vector<ll> B(N, 0);
    rep(i, N) B[i] = i;
    vector<ll> destiny(N, 0);
    rep(i, N) destiny[i] = i;
    vector<ll> change(M, 0);
    rep(i, M) {
        if(B[A[i]] == 0) change[i] = B[A[i] + 1];
        else if(B[A[i] + 1] == 0 ) change[i] = B[A[i]];
        ll tmp = B[A[i]];
        B[A[i]] = B[A[i] + 1];
        B[A[i] + 1] = tmp;
        destiny[B[A[i]]] = A[i];
        destiny[B[A[i] + 1]] = A[i] + 1;
    }
    rep(i, M) out(destiny[change[i]] + 1);
}
