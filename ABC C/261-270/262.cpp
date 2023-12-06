#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    vector<ll> data(N+5);
    for(ll i=1;i<=N;i++){
        cin>>data.at(i);
    }
    ll count=0;
    ll ans=0;
    for(ll i=1;i<=N;i++){
        if(i==data.at(i)){
            count++;
        }
    }
    ans=(count*(count-1))/2;
    for(ll i=1;i<=N;i++){
        ll x;
        x=data.at(i);
        if(data.at(x)==i && x>i && max(x,i)==x && min(x,i)==i){
            ans++;
        }
    }
    cout<<ans<<endl;
}