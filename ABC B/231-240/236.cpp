#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    cin>>N;
    ll S=2*N*(N+1);
    ll sum=0;
    for(ll i=0;i<4*N-1;i++){
        ll x;
        cin>>x;
        sum+=x;
    }
    cout<<S-sum<<endl;
}