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

vector<ll> prime;
vector<bool> is_prime;

void prime_func(ll N){
    for(ll i=0;i<=N;i++){
        is_prime.push_back(true);
    }
    is_prime.at(0)=false;
    is_prime.at(1)=false;
    for(ll i=2;i<=N;i++){
        if(is_prime.at(i)){
            prime.push_back(i);
            for(ll j=2*i;j<=N;j+=i){
                is_prime.at(j)=false;
            }
        }
    }
}

int main() {
    ll N;cin>>N;
    prime_func(cbrt(N));
    ll ans=0;
    for(auto q:prime){
        if(q*q*q>2*N) break;
        for(auto p:prime){
            if(p>=q) break;
            if(p*q*q*q>N) break;
            ans++;
        }
    }
    out(ans);
}