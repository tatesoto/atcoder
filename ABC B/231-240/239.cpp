#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll x;
    cin>>x;
    ll ans;
    if(x>=0 || x%10==0){
        ans=x/10;
    }
    else{
        ans=x/10-1;
    }
    cout<<ans<<endl;
}