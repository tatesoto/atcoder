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
    vector<ll> x(N),y(N);
    rep(i,N) cin>>x.at(i)>>y.at(i);
    vector<ll> X=x;
    vector<ll> Y=y;
    sort(all(X));
    sort(all(Y));
    ll mx=X.at(N/2);
    ll my=Y.at(N/2);
    ll ans=0;
    rep(i,N){
        ans+=abs(x.at(i)-mx)+abs(y.at(i)-my);
    }
    out(ans);
}