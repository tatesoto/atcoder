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

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main() {
    ll N;cin>>N;
    set<vector<ll>> s;
    vector<ll> x(N),y(N);
    rep(i,N) cin>>x.at(i)>>y.at(i);
    rep(i,N){
        for(ll j=i+1;j<N;j++){
            ll dx=x.at(i)-x.at(j);
            ll dy=y.at(i)-y.at(j);
            ll g=gcd(dx,dy);
            dx/=g;
            dy/=g;
            s.insert({dx,dy});
            s.insert({-dx,-dy});
        }   
    }
    out(s.size());
}