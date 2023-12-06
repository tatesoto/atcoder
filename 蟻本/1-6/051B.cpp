#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll K,S;
    cin>>K>>S;
    ll count=0;
    for(ll i=0;i<=K;i++){
        for(ll j=0;j<=K;j++){
            if(0<=S-i-j && S-i-j<=K){
                count++;
            }
        }
    }
    cout<<count<<endl;
}