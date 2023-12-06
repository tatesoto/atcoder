#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N,P;
    cin>>N>>P;
    ll count=0;
    for(ll i=0;i<N;i++){
        ll x;
        cin>>x;
        if(x<P){
            count++;
        }
    }
    cout<<count<<endl;
}