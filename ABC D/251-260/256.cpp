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
    ll N; cin>>N;
    vector<pair<ll,ll>> v;
    rep(i,N){
        ll left,right; cin>>left>>right;
        v.push_back({left,right});
    }
    sort(all(v));
    rep(i,N-1){
        if(v.at(i).second>=v.at(i+1).first){
            v.at(i+1)={v.at(i).first, max(v.at(i).second,v.at(i+1).second)};
            v.at(i).first=-1;
        }
    }
    rep(i,N){
        if(v.at(i).first==-1) continue;
        out(v.at(i).first<<" "<<v.at(i).second);
    }
}