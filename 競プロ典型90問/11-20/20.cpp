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

ll pow(ll x,ll N){
    ll ans=1;
    while(N>0){
        if(N & 1){
            ans*=x;
        }
        x*=x;
        N>>=1;
    }
    return ans;
}

int main() {
    ll a,b,c;cin>>a>>b>>c;
    if(a<pow(c,b)) out("Yes");
    else out("No");
}