#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
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
    ll N, K;cin>>N>>K;
    vector<ll> P(N);
    rep(i, N) cin>>P[i], P[i]--;
    vector<ll> C(N);
    rep(i, N) cin>>C[i];
    ll ans = -INF;
    rep(i, N){
        ll n = 0;
        ll s = 0;
        ll pos = i;
        vector<ll> sum;
        sum.push_back(0);
        do{
            pos = P[pos];
            n++;
            s += C[pos];
            sum.push_back(s);
        }
        while(pos != i);
        for(ll r = 1; r <= min(K, n); r++){
            ll p = (K-r)/n;
            chmax(ans, max(p*s+sum[r], sum[r]));
        }
    }
    out(ans);
}
