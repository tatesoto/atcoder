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
    ll T;cin>>T;
    vector<ll> A(N+1);
    rep(i,N) cin>>A.at(i+1);
    vector<ll> sum(N+1,0);
    for(ll i=1;i<=N;i++) sum.at(i)=sum.at(i-1)+A.at(i);
    T%=sum.at(N);
    ll song=0;
    ll ans=0;
    for(ll i=1;i<=N;i++){
        if(T-sum.at(i)<0){
            song=i;
            ans=T-sum.at(i-1);
            cout<<song<<" "<<ans<<endl;
            return 0;
        }
    }

}