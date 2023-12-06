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
    ll N,S; cin>>N>>S;
    vector<ll> a(N+1);
    for(ll i=1;i<=N;i++) cin>>a.at(i);
    vector<vector<bool>> dp(N+1,vector<bool>(S+1,false));
    dp.at(0).at(0)=true;
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<=S;j++){
            if(j-a.at(i)<0){
                dp.at(i).at(j)=dp.at(i-1).at(j);
            }
            else{
                dp.at(i).at(j)=(dp.at(i-1).at(j)||dp.at(i-1).at(j-a.at(i)));
            }
        }
    }
    if(dp.at(N).at(S)){
        out("Yes");
    }
    else{
        out("No");
    }
}