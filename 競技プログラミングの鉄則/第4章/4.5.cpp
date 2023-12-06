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

int main() {
    string S,T;
    cin>>S>>T;
    ll s=S.size();
    ll t=T.size();
    vector<vector<ll>> dp(s+1,vector<ll>(t+1,0));
    for(ll i=1;i<=s;i++){
        for(ll j=1;j<=t;j++){
            chmax(dp.at(i).at(j),max(dp.at(i-1).at(j),dp.at(i).at(j-1)));
            if(S.at(i-1)==T.at(j-1)){
                chmax(dp.at(i).at(j),dp.at(i-1).at(j-1)+1);
            }
        }
    }
    out(dp.at(s).at(t));
}