#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t a,b,x;
    cin>>a>>b>>x;
    int64_t A=(a-1)/x;
    if(a==0){
        A=-1;
    }
    int64_t B=b/x;
    cout<<B-A<<endl;
}