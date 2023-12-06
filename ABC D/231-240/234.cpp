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
    ll N,K;
    cin>>N>>K;
    vector<ll> p(N+1);
    for(ll i=1;i<=N;i++){
        cin>>p.at(i);
    }
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(ll i=1;i<=K;i++){
        pq.push(p.at(i));
    }
    out(pq.top());
    for(ll i=K+1;i<=N;i++){
        if(pq.top()<p.at(i)){
            pq.pop();
            pq.push(p.at(i));
        }
        out(pq.top());
    }
}