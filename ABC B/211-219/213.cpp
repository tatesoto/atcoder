#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    vector<ll> data(N);
    for(ll i=0;i<N;i++){
        ll x;
        cin>>x;
        data.at(i)=1000000*(10000000000-x)+i+1;
    }
    sort(data.begin(),data.end());
    cout<<data.at(1)%1000000<<endl;
}