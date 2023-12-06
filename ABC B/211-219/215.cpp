#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    for(ll i=0;i<100;i++){
        ll x=pow(2,i);
        if(x>N){
            cout<<i-1<<endl;
            return 0;
        }
    }
}