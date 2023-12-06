#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,A,B;
    cin>>N>>A>>B;
    int Sum=0;
    for(int i=0;i<N;i++){
        int sum=0;
        int j=i+1;
        sum+=j%10;
        sum+=(j%100)/10;
        sum+=(j%1000)/100;
        sum+=(j%10000)/1000;
        sum+=j/10000;
        if(sum>=A && sum<=B){
            Sum+=j;
        }
    }
    cout << Sum <<endl;
}