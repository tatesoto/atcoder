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
    ll a,b,c;
    cin>>a>>b;
    if(a==b){
        out("1.000");
        return 0;
    }
    if(b==0){
        out("0.000");
        return 0;
    }
    b*=1000;
    b=2*b+a;
    a*=2;
    c=b/a;
    cout<<"0."<<c<<endl;
}