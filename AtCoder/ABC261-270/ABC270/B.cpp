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
    ll X,Y,Z;cin>>X>>Y>>Z;
    if(X*Y<0||abs(X)<abs(Y)){
        out(abs(X));
    }
    else if(Y*Z<0){
        out(2*abs(Z)+abs(X));
    }
    else if(abs(Y)<abs(Z)){
        out(-1);
    }
    else{
        out(abs(X));
    }
}