#include <bits/stdc++.h>
using namespace std;

int main(){
    int X,Y;
    cin>> X>>Y;
    int N;
    cin>>N;
    int sum=0;
    int mod=N%3;
    sum+=mod*X;
    N/=3;
    if(3*X<=Y){
        sum+=3*X*N;
    }
    else{
        sum+=Y*N;
    }
    cout<<sum<<endl;
}