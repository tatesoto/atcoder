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
    ll Q;cin>>Q;
    vector<vector<ll>> v(N);
    rep(i,N){
        ll L;cin>>L;
        rep(j,L){
            ll a;cin>>a;
            v.at(i).push_back(a);
        }
    }
    rep(i,Q){
        ll s,t;cin>>s>>t;
        out(v.at(s-1).at(t-1));
    }
}