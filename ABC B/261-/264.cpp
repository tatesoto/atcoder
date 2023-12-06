#include <bits/stdc++.h>
using namespace std;

int main(){
    int R,C;
    cin>>R>>C;
    int r=min(R,16-R);
    int c=min(C,16-C);
    bool color=true;
    if(r%2==1){
        if(c%2==0 && c<=r){
            color=false;
        }
    }
    else{
        if(c%2==1 && c<=r){
        }
        else{
            color=false;
        }
    }
    if(color){
        cout<<"black"<<endl;
    }
    else{
        cout<<"white"<<endl;
    }
}