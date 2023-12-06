#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    cin>>N;
    set<ll> data;
    for(ll i=0;i<N;i++){
        ll x;
        cin>>x;
        data.insert(x);
    }
    for(ll i=0;i<2500;i++){
        if(!data.count(i)){
            cout<<i<<endl;
            return 0;
        }
    }
}