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

long double a,b;
long double f(ll x){
    if(x<1){
        return INF;
    }
    long double ans=0;
    ans+=b*(x-1);
    ans+=a*sqrt(x)/x;
    return ans;
}

int main() {
    cin>>a>>b;
    long double ans=INF;
    long double c=a*a;
    c/=4;
    c/=b*b;
    c=cbrt(c);
    ll x=c-1000000;
    for(ll i=0;i<2000000;i++){
        chmin(ans,f(x+i));
    }
    cout<<fixed<<setprecision(16);
    out(ans);
}