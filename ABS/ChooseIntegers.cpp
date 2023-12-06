#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    int ans=false;
    for(int i=1;i<B;i++){
        if(i*A%B==0){
            continue;
        }
        if(C%((i*A)%B)==0){
            ans=true;
            break;
        }
    }
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}