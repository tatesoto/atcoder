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
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    vector<ll> s(N+1,0);
    rep(i,N) s.at(i+1)=s.at(i)+a.at(i);
    map<ll,ll> m;
    ll ans=0;
    rep(i,N){
        m[s.at(i)]++;
        //s,at(i+1)-s.at(j)=Kなるjの数を足す
        ans+=m[s.at(i+1)-K];
    }
    out(ans);
}