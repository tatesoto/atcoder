#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll a,b;
    cin>>a>>b;
    string ans="Yes";
    if(b==10){
        if(a!=1 && a!=9){
            ans="No";
        }
    }
    else if(b!=a+1){
        ans="No";
    }
    cout<<ans<<endl;
}