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
    ll N, X;cin>>N>>X;
    vector<ll> A(N-1);
    rep(i, N-1) cin>>A[i];
    sort(all(A));
    ll m = A[0];
    ll M = A[N-2];
    ll sum = 0;
    rep(i, N-1) sum += A[i];
    rep(i, 101){
        ll res = sum + i;
        if(i < m) res -=  (i + M);
        else if (i > M) res -= (m + i);
        else res -= (m + M);
        if(res >= X){
            out(i);
            return 0;
        }
    }    
    out(-1);
}