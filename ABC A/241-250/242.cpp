#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    double A,B,C,X;
    cin>>A>>B>>C>>X;
    double p;
    if(X<=A){
        p=1;
    }
    else if(X>B){
        p=0;
    }
    else{
        p=C/(B-A);
    }
    cout<<p<<endl;
}