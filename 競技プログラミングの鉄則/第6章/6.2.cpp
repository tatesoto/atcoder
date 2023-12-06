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
    ll N,M,B;cin>>N>>M>>B;
    ll sumA=0;
    ll sumC=0;
    rep(i,N){
        ll x;cin>>x;
        sumA+=x;
    }
    rep(i,M){
        ll x;cin>>x;
        sumC+=x;
    }
    out(M*sumA+M*N*B+N*sumC);
}