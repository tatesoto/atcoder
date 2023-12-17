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
    vector<ll> W(N), X(N);
    rep(i, N) cin>>W[i]>>X[i];
    vector<ll> cnt(24, 0);
    rep(i, N){
        rep(j, 9){
            cnt[(33-X[i]+j)%24] += W[i];
        }
    }
    ll ans = 0;
    rep(i, 24){
        chmax(ans, cnt[i]);
    }
    out(ans);
}