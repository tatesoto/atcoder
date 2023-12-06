#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N;cin>>N;
    vector<ll> a(N);
    rep(i, N) cin>>a.at(i);
    vector<vector<ll>> dp(N+1, vector<ll>(2, INF));
    dp.at(1).at(1) = a.at(0);
    for(ll i=1;i<N;i++){
        chmin(dp.at(i+1).at(1), dp.at(i).at(0) + a.at(i));
        chmin(dp.at(i+1).at(1), dp.at(i).at(1) + a.at(i));
        chmin(dp.at(i+1).at(0), dp.at(i).at(1));
    }
    ll ans;
    ans = min(dp.at(N).at(0), dp.at(N).at(1));
    dp.resize(N+1, vector<ll>(2, INF));
    dp.at(1).at(0) = 0;
    for(ll i=1;i<N;i++){
        chmin(dp.at(i+1).at(1), dp.at(i).at(0) + a.at(i));
        chmin(dp.at(i+1).at(1), dp.at(i).at(1) + a.at(i));
        chmin(dp.at(i+1).at(0), dp.at(i).at(1));
    }
    chmin(ans, dp.at(N).at(1));
    out(ans);
}