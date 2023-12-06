#include <bits/stdc++.h>
using namespace std;

int main(){
    double a,b,d;
    cin>>a>>b>>d;
    double x;
    x= M_PI*(d/180);
    double A,B;
    A=a*cos(x)-b*sin(x);
    B=a*sin(x)+b*cos(x);
    cout<<fixed<<setprecision(10);
    cout<<A<<" "<<B<<endl;
}