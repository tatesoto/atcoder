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
    map<ll,ll> mp;
    rep(i,N){
        mp[a.at(i)]=1;
    }
    auto iter=mp.end();
    rep(i,mp.size()){
        iter--;
        auto p=*iter;
        mp[p.first]=i;
    }
    vector<ll> cnt(N,0);
    rep(i,N){
        cnt.at(mp[a.at(i)])++;
    }
    rep(i,N){
        out(cnt.at(i));
    }
}