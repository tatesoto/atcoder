#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll A,B;
    cin>>A>>B;
    if(0<A){
        if(B==0){
            cout<<"Gold"<<endl;
        }
        else{
            cout<<"Alloy"<<endl;
        }
    }
    else{
        cout<<"Silver"<<endl;
    }
}