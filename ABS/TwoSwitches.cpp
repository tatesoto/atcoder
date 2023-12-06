#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int ans=0;
    if(C<B){
        if(A<=C && B<=D){
            ans=B-C;
        }
        else if(A>=C && B<=D){
            ans=B-A;
        }
        else if(A<=C && B>=D){
            ans=D-C;
        }
        else if(A>=C && B>=D){
            ans=D-A;
        }
    }
    else{
        ans=0;
    }
    cout <<ans<<endl;
}