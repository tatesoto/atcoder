#include <bits/stdc++.h>
using namespace std;

int main(){
    int s;
    cin>>s;
    int a,b,c;
    a=s/100;
    b=(s%100)/10;
    c=s%10;
    cout <<a+b+c<<endl;
}