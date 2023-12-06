#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,W;
    cin>>N>>W;
    map<ll,ll> data;
    rep(i,N){
        ll a,b;
        cin>>a>>b;
        if(data.count(-a)){
            data[-a]+=b;
            continue;
        }
        data[-a]=b;
    }
    ll delicious=0;
    for(auto p:data){
        if(W>=p.second){
            delicious+=-p.first*p.second;
            W-=p.second;
        }
        else{
            delicious+=-p.first*W;
            W=0;
            out(delicious);
            return 0;
        }
    }
    out(delicious);
}