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
    ll N;
    cin>>N;
    vector<ll> p(N);
    rep(i,N) cin>>p.at(i);
    vector<ll> count(N,0);
    rep(i,N){
        count.at((p.at(i)+1-i+N)%N)++;
        count.at((p.at(i)-i+N)%N)++;
        count.at((p.at(i)+N-1-i)%N)++;
    }
    ll ans=0;
    rep(i,N){
        chmax(ans,count.at(i));
    }
    out(ans);
}