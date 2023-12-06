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
    ll N,X;cin>>N>>X;
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    ll pos=lower_bound(all(a),X)-a.begin();
    if(pos<=N && a.at(pos)==X){
        out(pos+1);
    }
    else{
        out(-1);
    }
}