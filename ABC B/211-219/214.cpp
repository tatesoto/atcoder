#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll S,T;
    cin>>S>>T;
    ll count=0;
    for(ll i=0;i<101;i++){
        for(ll j=0;j<101;j++){
            for(ll k=0;k<101;k++){
                if(i+j+k<=S && i*j*k<=T){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
}