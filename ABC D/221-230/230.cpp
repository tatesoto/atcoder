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
    ll N,D;cin>>N>>D;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> s;
    rep(i,N){
        ll x,y;cin>>x>>y;
        s.push((make_pair(y,x)));
    }
    ll now=0;
    ll cnt=1;
    pair<ll,ll> p=s.top();
    now=p.first;
    s.pop();
    while(!s.empty()){
        pair<ll,ll> q=s.top();
        if(q.second>now+D-1){
            now=q.first;
            cnt++;
        }
        s.pop();
    }
    out(cnt);
}