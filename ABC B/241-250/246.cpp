#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    double A,B;
    cin>>A>>B;
    if(A==0){
        if(B>0){
            cout<<0<<" "<<1<<endl;
        }
        else{
            cout<<0<<" "<<-1<<endl;
        }
    }
    else{
        double x=B/A;
        double theta=atan(x);
        cout<<fixed<<setprecision(10);
        cout<<cos(theta)<<" "<<sin(theta)<<endl;
    }
}