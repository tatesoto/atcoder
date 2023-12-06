#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ans=0;

void blue(ll N,ll X,ll Y,ll x,ll y){
    if(N==1){
        ans=y;
    }
    else{
        blue(N-1,X,Y,(X+1)*x+y,x*X*Y+Y*y);
    }
}

int main() {
    ll N,X,Y;
    cin>>N>>X>>Y;
    blue(N,X,Y,1,0);
    cout<<ans<<endl;
}