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
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    ll Q;cin>>Q;
    rep(i,Q){
        ll q;cin>>q;
        if(q==1){
            ll k,x;cin>>k>>x;
            k--;
            a.at(k) = x;
        }
        else{
            ll k;cin>>k;
            k--;
            out(a.at(k));
        }
        
    }
}