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
//素因数分解
map<ll,ll> prime_factor(ll N){
    map<ll,ll> ans;
    for(ll i=2;i*i<=N;i++){
        while(N%i==0){
            ans[i]++;
            N/=i;
        }
    }
    if(N!=1){
        ans[N]=1;
    }
    return ans;
}

int main() {
    ll N;cin>>N;
    vector<ll> v(N);
    rep(i,N) cin>>v.at(i);
    ll g=v.at(0);
    rep(i,N){
        g=gcd(g,v.at(i));
    }
    rep(i,N){
        v.at(i)/=g;
    }
    ll cnt=0;
    rep(i,N){
        map<ll,ll> mp=prime_factor(v.at(i));
        for(auto p:mp){
            if(p.first==2){
                cnt+=p.second;
            }
            else if(p.first==3){
                cnt+=p.second;
            }
            else{
                out(-1);
                return 0;
            }
        }
    }
    out(cnt);
}