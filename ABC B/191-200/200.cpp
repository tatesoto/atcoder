#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,K;
    cin>>N>>K;
    rep(i,K){
        if(N%200==0){
            N/=200;
        }
        else{
            N*=1000;
            N+=200;
        }
    }
    out(N);
}