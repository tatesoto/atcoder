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
    vector<ll> num(D+2,0);
    rep(i,N){
        ll l,r;cin>>l>>r;
        num.at(l)++;
        num.at(r+1)--;
    }
    ll ans=0;
    for(ll i=1;i<=D;i++){
        ans+=num.at(i);
        out(ans);
    }
}