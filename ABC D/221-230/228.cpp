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

const ll N=1048576;
vector<ll> v;
set<ll> s;

int main() {
    ll Q;cin>>Q;
    rep(i,2*N){
        s.insert(i);
    }
    rep(i,Q){
        ll t,x;cin>>t>>x;
        v.resize(N,INF);
        if(t==1){
            ll h=x%N;
            h=*s.lower_bound(h);
            h%=N;
            s.erase(h);
            s.erase(h+N);
            v.at(h)=x;
        }
        else{
            if(v.at(x%N)==INF){
                out(-1);
            }
            else{
                out(v.at(x%N));
            }
        }
    }
}