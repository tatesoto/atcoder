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

int main() {
    ll N;cin>>N;
    ll X,Y;cin>>X>>Y;
    vector<ll> a(N+1),b(N+1);
    for(ll i=1;i<=N;i++){
        cin>>a.at(i)>>b.at(i);
    }
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(600, vector<ll>(600, INF)));
    dp.at(0).at(0).at(0) = 0;
    for(ll i=1;i<=N;i++){
        rep(j,600){
            rep(k,600){
                chmin(dp.at(i).at(j).at(k), dp.at(i-1).at(j).at(k));
                chmin(dp.at(i).at(min(599LL, j + a.at(i))).at(min(599LL, k + b.at(i))), dp.at(i-1).at(j).at(k) + 1);
            }
        }
    }
    ll ans = INF;
    for(ll j = X;j<600;j++){
        for(ll k=Y;k<600;k++){
            chmin(ans, dp.at(N).at(j).at(k));
        }
    }
    if(ans == INF) out(-1);
    else out(ans);
}