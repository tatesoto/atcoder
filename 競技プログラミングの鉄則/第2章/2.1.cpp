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
    ll N,Q;cin>>N>>Q;
    vector<ll> v(N+1);
    for(ll i=1;i<=N;i++){
        cin>>v.at(i);
    }
    vector<ll> s(N+2,0);
    for(ll i=1;i<=N;i++){
        s.at(i+1)=s.at(i)+v.at(i);
    }
    rep(i,Q){
        ll l,r;
        cin>>l>>r;
        out(s.at(r+1)-s.at(l));
    }
}