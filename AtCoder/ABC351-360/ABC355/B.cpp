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
    vector<ll> A(N), B(M);
    rep(i, N) cin>>A[i];
    rep(i, M) cin>>B[i];
    vector<pair<ll,ll>> C;
    rep(i, N) C.push_back({A[i], 0});
    rep(i, M) C.push_back({B[i], 1});
    sort(all(C));
    rep(i, N+M) {
        if(i == 0) continue;
        if(C[i].second == C[i-1].second && C[i].second == 0) {
            out("Yes");
            return 0;
        }
    }
    out("No");
}