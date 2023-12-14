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
    vector<vector<bool>> meet(N, vector<bool>(N, false));
    rep(i, M){
        ll k;cin>>k;
        vector<ll> A(k);
        rep(j, k) cin>>A[j];
        rep(j, k){
            rep(l, k){
                if(j == l) continue;
                meet[A[j]-1][A[l]-1] = true;
            }
        }
    }
    rep(i, N){
        rep(j, N){
            if(i == j) continue;
            if(!meet[i][j]){
                out("No");
                return 0;
            }
        }
    }
    out("Yes");
}
