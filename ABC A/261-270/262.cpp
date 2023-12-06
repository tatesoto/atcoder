#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll Y;
    cin>>Y;
    ll ans;
    if(Y%4==2){
        ans=Y;
    }
    else{
        ll x=Y%4;
        if(x==3){
            ans=Y+3;
        }
        else if(x==0){
            ans=Y+2;
        }
        else{
            ans=Y+1;
        }
    }
    cout<<ans<<endl;
}