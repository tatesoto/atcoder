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
    Graph dp(N+1,vector<ll>(N+1));
    for(ll i=1;i<=N;i++){
        cin>>dp.at(N).at(i);
    }
    for(ll i=N-1;i>=1;i--){
        for(ll j=1;j<=i;j++){
            if(i%2==1){
                dp.at(i).at(j)=max(dp.at(i+1).at(j),dp.at(i+1).at(j+1));
            }
            else{
                dp.at(i).at(j)=min(dp.at(i+1).at(j),dp.at(i+1).at(j+1));
            }
        }
    }
    out(dp.at(1).at(1));
}