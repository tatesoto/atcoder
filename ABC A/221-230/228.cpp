#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll S,T,X;
    cin>>S>>T>>X;
    if(S<T){
        if(S<=X&&X<T){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    else{
        if(S<=X||X<T){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }   
    }
}