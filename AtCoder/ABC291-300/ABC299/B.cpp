#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N, T;cin>>N>>T;
    set<ll> color;
    vector<ll> c(N);
    map<ll,vector<pair<ll, ll>>> mp;
    rep(i, N){
        ll c_;cin>>c_;
        c.at(i) = c_;
        color.insert(c_);
    }
    rep(i, N){
        ll r;cin>>r;
        mp[c.at(i)].push_back({r, i});
    }
    ll ans = -1;
    ll num = -1;
    if(color.count(T)){
        for(auto p:mp[T]){
            if(chmax(num, p.first)) ans = p.second;
        }
    }   
    else{
        for(auto p:mp[c.at(0)]){
            if(chmax(num, p.first)) ans = p.second;
        }
    }
    out(ans+1);
}