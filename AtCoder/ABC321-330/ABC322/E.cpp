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

ll vto6(vector<ll> v){
    ll res = 0;
    rep(i, 5){
        res*=6;
        res+=v[4-i];
    }
    return res;
}

vector<ll> sixtov(ll n){
    vector<ll> res;
    rep(i, 5){
        ll x = n%6;
        res.push_back(x);
        n/=6;
    }
    return res;
}


int main() {
    ll N, K, P;cin>>N>>K>>P;
    vector<ll> C(N+1);
    vector<vector<ll>> A(N+1);
    rep(i, N){
        cin>>C[i+1];
        rep(j, K){
            ll a;cin>>a;A[i+1].push_back(a);
        }
    }
    vector<vector<ll>> dp(N+1, vector<ll>(7776, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        rep(j, 7776){
            chmin(dp[i][j], dp[i-1][j]);
            
            auto v = sixtov(j);
            rep(k, K){
                v[k] = min(P, v[k]+A[i][k]);
            }
            auto n = vto6(v);
            chmin(dp[i][n], dp[i-1][j] + C[i]);
        }
    }
    ll m = 0;
    rep(i, K){
        m*=6;
        m+=P;
    }
    if(dp[N][m] == INF ) out(-1);
    else out(dp[N][m]);
}