#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    cin>>N;
    vector<ll> high(N+1,0);
    for(ll i=0;i<N;i++){
        cin>>high.at(i);
    }
    ll h=high.at(0);
    for(ll i=0;i<N;i++){
        if(high.at(i)<high.at(i+1)){
            h=high.at(i+1);
        }
        else{
            cout<<h<<endl;
            return 0;
        }
    }
}