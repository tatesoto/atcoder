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
    ll a,b,c,d;
    a=INF;
    c=INF;
    b=-1;
    d=-1;
    rep(i,10){
        rep(j,10){
            char x; cin>>x;
            if(x=='#'){
                chmin(a,i+1);
                chmax(b,i+1);
                chmin(c,j+1);
                chmax(d,j+1);
            }
        }
    }
    out(a<<" "<<b);
    out(c<<" "<<d);
}