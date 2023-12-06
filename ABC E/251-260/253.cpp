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
    ll N, M, K;cin>>N>>M>>K;
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));
    vector<vector<ll>> s(N+1, vector<ll>(M+1, 0));
    for(ll j=1;j<=M;j++){
        dp.at(1).at(j) = 1;
        s.at(1).at(j) = dp.at(1).at(j) + s.at(1).at(j-1);
    }
    for(ll i=1;i<N;i++){
        for(ll j=1;j<=M;j++){
            ll k = s.at(i).at(M) - s.at(i).at(min(M, j+K-1)) + s.at(i).at(max(0LL, j-K));
            if(K == 0){
                k = s.at(i).at(M);
            }
            k = ((k%mod)+mod)%mod;
            dp.at(i+1).at(j) = k;
            s.at(i+1).at(j) = dp.at(i+1).at(j) + s.at(i+1).at(j-1);
            s.at(i+1).at(j) = ((s.at(i+1).at(j)%mod)+mod)%mod;
        }
    }
    out(s.at(N).at(M));
}