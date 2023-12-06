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
    ll a,b;cin>>a>>b;
    vector<bool> dp(N+1,false);
    rep(i,N+1){
        if(i-a>=0&&dp.at(i-a)==false) dp.at(i)=true;
        if(i-b>=0&&dp.at(i-b)==false) dp.at(i)=true;
    }
    if(dp.at(N)){
        out("First");
    }
    else{
        out("Second");
    }
}