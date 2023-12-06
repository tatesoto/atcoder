#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    int X;
    cin>>X;
    int count=0;
    for(int i=0;i<=A;i++){
        for(int j=0;j<=B;j++){
            if(X-500*i-100*j>=0 && X-500*i-100*j<=50*C){
                count++;
            }
        }
    }
    cout << count<<endl;
}