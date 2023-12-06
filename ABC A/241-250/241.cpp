#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<ll> data(10);
    for(ll i=0;i<10;i++){
        cin>>data.at(i);
    }
    ll ans=0;
    for(ll i=0;i<3;i++){
        ans=data.at(ans);
    }
    cout<<ans<<endl;
}