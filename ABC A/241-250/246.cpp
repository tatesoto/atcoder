#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<ll> x(3),y(3);
    for(ll i=0;i<3;i++){
        cin>>x.at(i)>>y.at(i);
    }
    ll ansx,ansy;
    ll judge=false;
    for(ll i=0;i<2;i++){
        for(ll j=i+1;j<3;j++){
            if(x.at(i)==x.at(j)){
                ansx=x.at(3-i-j);
            }
            if(y.at(i)==y.at(j)){
                ansy=y.at(3-i-j);
            }
        }
    }
    cout<<ansx<<" "<<ansy<<endl;
}