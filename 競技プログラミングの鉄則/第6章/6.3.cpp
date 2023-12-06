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
    ll D,N;cin>>D>>N;
    vector<ll> day(D+1,24);
    rep(i,N){
        ll l,r,h;
        cin>>l>>r>>h;
        for(ll j=l;j<=r;j++){
            chmin(day.at(j),h);
        }
    }
    ll ans=0;
    for(ll i=1;i<=D;i++){
        ans+=day.at(i);
    }
    out(ans);
}