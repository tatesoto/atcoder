#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> data(N+1,-1);
    for(ll i=1;i<=N;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        data.at(i)=x+y+z;
    }
    vector<ll> a=data;
    sort(all(a));
    reverse(all(a));
    for(auto x:data){
        if(x==-1){
            continue;
        }
        if(x+300>=a.at(K-1)){
            out("Yes");
        }
        else{
            out("No");
        }
    } 
}