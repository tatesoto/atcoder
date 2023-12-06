#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int upper,lower;
    upper=min(B,D); //point!!
    lower=max(A,C);
    cout<< max(0,upper-lower)<<endl; 
}