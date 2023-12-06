#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<ll> q(N);
    rep(i,N){
        ll p;
        cin>>p;
        q.at(p-1)=i+1;
    }
    for(auto x:q){
        out(x);
    }
}