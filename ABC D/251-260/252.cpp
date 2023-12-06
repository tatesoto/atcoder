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
    map<ll,ll> mp;
    rep(i,N){
        cin>>a.at(i);
    }
    rep(i,N){
        mp[a.at(i)]++;
    }
    vector<ll> s(mp.size()+1,0);
    ll cnt=1;
    for(auto p:mp){
        s.at(cnt)=p.second+s.at(cnt-1);
        cnt++;
    }
    auto iter=mp.begin();
    ll ans=0;
    for(ll i=1;i<=mp.size();i++){
        if(i==1||i==mp.size()){
            iter++;
            continue;
        }
        auto p=*iter;
        iter++;
        ll x=p.second;
        ans+=s.at(i-1)*(s.at(mp.size())-s.at(i))*x;
    }
    out(ans);
}