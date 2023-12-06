#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll A,B;
    cin>>A>>B;
    bool judge=true;
    while(A>0&&B>0){
        ll a,b;
        a=A%10;
        b=B%10;
        if(a+b>9){
            judge=false;
            break;
        }
        A/=10;
        B/=10;
    }
    if(judge){
        cout<<"Easy"<<endl;
    }
    else{
        cout<<"Hard"<<endl;
    }
}