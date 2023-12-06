#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
using Graph = vector<vector<ll>>;
const ll mod=10000;

int main() {
    ll N;cin>>N;
    ll ans=0;
    rep(i,N){
        char t;cin>>t;
        ll a;cin>>a;
        if(t=='+'){
            ans+=a;
            ans%=mod;
            out(ans);
        }
        else if(t=='-'){
            ans-=a;
            ans%=mod;
            if(ans<0){
                ans+=mod;
            }
            out(ans);
        }
        else{
            ans*=a;
            ans%=mod;
            out(ans);
        }
    }
}