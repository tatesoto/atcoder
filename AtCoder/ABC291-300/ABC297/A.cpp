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
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N,D;cin>>N>>D;
    vector<ll> v(N);
    rep(i, N){
        cin>>v.at(i);
    }
    rep(i, N){
        if(i==0) continue;
        if(v.at(i) - v.at(i-1) <= D){
            out(v.at(i));
            return 0;
        }
    }
    out(-1);
}