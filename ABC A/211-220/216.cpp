#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    double N;
    cin>>N;
    ll n=N*10;
    n%=10;
    ll ans=N;
    cout<<ans;
    if(n<=2){
        cout<<"-";
    }
    else if(n<=6){
    }
    else{
        cout<<"+";
    }
    cout<<endl;
}