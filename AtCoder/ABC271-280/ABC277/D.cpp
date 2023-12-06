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
    ll N,M;cin>>N>>M;
    map<ll,ll> mp;
    ll allsum=0;
    rep(i,N){
        ll a;cin>>a;
        mp[a]++;
        mp[a+M]++;
        allsum+=a;
    }
    auto iter=mp.begin();
    ll maxsum=-1;
    ll nowsum=0;
    while(iter!=mp.end()){
        auto p=*iter;
        ll now=p.first;
        if(now<M) nowsum+=(p.first)*(p.second);
        else nowsum+=(p.first-M)*(p.second);
        if(!mp.count(now+1)){
            chmax(maxsum,nowsum);
            nowsum=0;
        }
        iter++;
    }
    out(max(allsum-maxsum,0LL));
}