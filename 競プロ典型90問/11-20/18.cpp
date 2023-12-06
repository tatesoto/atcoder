#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
ld T;
ld L,X,Y;
ld solve(ll E){
    ld m=sqrt(X*X+(Y+L*sin(2*M_PI*E/T)/2)*(Y+L*sin(2*M_PI*E/T)/2));
    ld theta=atan2(L*(1-cos(2*M_PI*E/T))/2,m);
    return 180*theta/M_PI;
}

int main() {
    cin>>T;
    cin>>L>>X>>Y;
    ll Q;cin>>Q;
    rep(i,Q){
        ld E;cin>>E;
        cout<<setprecision(16);
        out(solve(E));
    }
}