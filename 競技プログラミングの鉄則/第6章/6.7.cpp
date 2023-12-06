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
    vector<ll> a(N),b(N);
    rep(i,N){
        cin>>a.at(i)>>b.at(i);
    }
    ll ans=0;
    for(ll i=0;i<=99;i++){
        for(ll j=0;j<=99;j++){
            ll count=0;
            rep(k,N){
                if(a.at(k)>=i&&a.at(k)<=i+K&&b.at(k)>=j&&b.at(k)<=j+K){
                    count++;
                }
                chmax(ans,count);
            }
        }
    }
    out(ans);
}