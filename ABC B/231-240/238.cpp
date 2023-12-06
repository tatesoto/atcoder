#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    cin>>N;
    vector<ll> data(N);
    for(ll i=0;i<N;i++){
        cin>>data.at(i);
    }
    vector<ll> div(N);
    ll now=0;
    for(ll i=0;i<N;i++){
        ll x=(now+data.at(i))%360;
        div.at(i)=x;
        now=x;
    }
    div.push_back(360);
    div.push_back(0);
    sort(div.begin(),div.end());
    ll ans=0;
    for(ll i=0;i<=N;i++){
        ans=max(ans,abs(div.at(i+1)-div.at(i)));
    }
    cout<<ans<<endl;
}