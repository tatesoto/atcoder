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
    vector<ll> coin(3);
    rep(i,3) cin>>coin.at(i);
    sort(all(coin));
    ll a,b,c;
    a=coin.at(2);
    b=coin.at(1);
    c=coin.at(0);
    ll ans=INF;
    for(ll i=0;a*i<=N;i++){
        for(ll j=0;a*i+b*j<=N;j++){
            if((N-a*i-b*j)%c==0){
                ll k=(N-a*i-b*j)/c;
                chmin(ans,i+j+k);
            }
        }
    }
    out(ans);
}