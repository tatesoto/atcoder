#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=1000000007;
using Graph = vector<vector<ll>>;

int main() {
    ll N;cin>>N;
    string S;cin>>S;
    S="1"+S;
    vector<vector<ll>> dp(N+1,vector<ll>(8,0));
    string atcoder="0atcoder";
    dp.at(0).at(0)=1;
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<=7;j++){
            if(S.at(i)==atcoder.at(j)){
                dp.at(i).at(j)+=dp.at(i-1).at(j-1);
                dp.at(i).at(j)%=mod;
            }
            dp.at(i).at(j)+=dp.at(i-1).at(j);
            dp.at(i).at(j)%=mod;
        }
    }
    out(dp.at(N).at(7));
}