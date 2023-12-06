#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<ll> a(N),P(N),X(N);
    rep(i,N){
        cin>>a.at(i)>>P.at(i)>>X.at(i);
    }
    ll sum=10000000000;
    rep(i,N){
        if(a.at(i)<X.at(i)){
            sum=min(sum,P.at(i));
        }
    }
    if(sum==10000000000){
        sum=-1;
    }
    out(sum);
}