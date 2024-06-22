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
    Graph a(N, vector<ll>(N));
    rep(i, N) {
        rep(j, N) {
            cin>>a[i][j];
        }
    }
    vector<ll> dp((1<<N), 0);
    vector<ll> cost((1<<N), 0);
    rep(S, (1<<N)) {
        rep(i, N) {
            for(int j = i+1; j < N; j++) {
                if((S>>i)%2 == 0) continue;
                if((S>>j)%2 == 0) continue;
                cost[S] += a[i][j]; 
            }
        }
    }
    dp[0] = 0;
    rep(S, (1<<N)) {
        for(int T = S; T > 0; T = (T-1)&S) {
            chmax(dp[S], dp[S-T] + cost[T]);
        }
    }
    out(dp[(1<<N)-1]);
}