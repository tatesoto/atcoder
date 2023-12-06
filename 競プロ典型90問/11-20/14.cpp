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
    vector<ll> a(N),b(N);
    rep(i,N) cin>>a.at(i);
    rep(i,N) cin>>b.at(i);
    sort(all(a));
    sort(all(b));
    ll ans=0;
    rep(i,N){
        ans+=abs(a.at(i)-b.at(i));
    }
    out(ans);
}