#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll a,b,c;
    cin>>a>>b>>c;
    if(min(a,c)<=b&&b<=max(a,c)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}