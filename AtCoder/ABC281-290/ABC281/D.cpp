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
    ll N,K,D;cin>>N>>K>>D;
    vector<ll> A(N+1,INF);
    rep(i,N) cin>>A.at(i+1);
    sort(all(A));
    reverse(all(A));
    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(K+1,vector<ll>(D,-1)));
    dp.at(0).at(0).at(0)=0;
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<=K;j++){
            for(ll k=0;k<D;k++){
                chmax(dp.at(i).at(j).at(k),dp.at(i-1).at(j).at(k));
                if(j>0&&dp.at(i-1).at(j-1).at(k)>=0) chmax(dp.at(i).at(j).at((k+A.at(i))%D),dp.at(i-1).at(j-1).at(k)+A.at(i));
            }
        }
    }
    out(dp.at(N).at(K).at(0));
}