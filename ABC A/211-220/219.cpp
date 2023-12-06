#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll X;
    cin>>X;
    ll ans=0;
    if(X<40){
        ans=40-X;
    }
    else if(X<70){
        ans=70-X;
    }
    else if(X<90){
        ans=90-X;
    }
    else{
        cout<<"expert"<<endl;
        return 0;
    }
    cout<<ans<<endl;
}