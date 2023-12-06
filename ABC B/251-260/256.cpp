#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    cin>>N;
    vector<ll> data(N);
    vector<ll> base(N,0);
    for(ll i=0;i<N;i++){
        cin>> data.at(i);
    }
    for(ll i=0;i<N;i++){
        for(ll j=0;j<=i;j++){
            base.at(j)+=data.at(i);
        }
    }
    ll count=0;
    for(ll i=0;i<N;i++){
        if(base.at(i)>=4){
            count++;
        }
    }
    cout << count<<endl;
}