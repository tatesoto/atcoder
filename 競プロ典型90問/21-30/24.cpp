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
    ll cnt=0;
    vector<ll> a(N),b(N);
    rep(i,N){
        cin>>a.at(i);
    }
    rep(i,N){
        cin>>b.at(i);
    }
    rep(i,N){
        cnt+=abs(a.at(i)-b.at(i));
    }
    if(cnt>K){
        out("No");
    }
    else{
        if((K+cnt)%2==0){
            out("Yes");
        }
        else{
            out("No");
        }
    }
}