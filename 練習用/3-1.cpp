#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int64_t L0=2;
    int64_t L1=1;
    if(N==1){
        cout<<1<<endl;
    }
    else{
        int64_t a;
        for(int i=0;i<N-1;i++){
        a=L1+L0;
        L0=L1;
        L1=a;
        }
        cout<<a<<endl;
    }

}