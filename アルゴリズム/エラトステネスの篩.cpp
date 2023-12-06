#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

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
    ll N;
    cin>>N;
    prime_func(N);
    for(auto x:prime){
        out(x);
    }
}