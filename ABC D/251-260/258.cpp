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
    ll N,X;cin>>N>>X;
    vector<ll> a(N+1),b(N+1);
    for(ll i=1;i<=N;i++){
        cin>>a.at(i)>>b.at(i);
    }
    vector<ll> minB(N+1,INF);
    for(ll i=1;i<=N;i++){
        chmin(minB.at(i),min(b.at(i),minB.at(i-1)));
    }
    vector<ll> clear(N+1,0);
    for(ll i=1;i<=N;i++){
        clear.at(i)=clear.at(i-1)+a.at(i)+b.at(i);
    }
    ll ans=INF;
    for(ll i=1;i<=N;i++){
        ll time=clear.at(i)+(X-i)*minB.at(i);
        chmin(ans,time);
    }
    out(ans);
}