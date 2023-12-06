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
    ll N,K;cin>>N>>K;
    priority_queue<pair<ll,ll>> pq;
    rep(i,N){
        ll a,b;cin>>a>>b;
        a-=b;
        pq.push(make_pair(b,a));
    }
    ll ans=0;
    rep(i,K){
        ans+=pq.top().first;
        ll a=pq.top().second;
        pq.pop();
        pq.push(make_pair(a,-INF));
    }
    out(ans);
}