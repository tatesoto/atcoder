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

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main() {
    ll N,A,B;cin>>N>>A>>B;
    ll a,b,c;
    a=N/A;
    b=N/B;
    ll ans;
    ll lcm=A*B/gcd(A,B);
    c=N/lcm;
    ans=(N*(N+1)-a*(a+1)*A-b*(b+1)*B+c*(c+1)*lcm)/2;
    out(ans);
}