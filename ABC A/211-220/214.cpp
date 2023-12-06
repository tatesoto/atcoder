#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    if(N<=125){
        cout<<4<<endl;
    }
    else if(N<=211){
        cout<<6<<endl;
    }
    else{
        cout<<8<<endl;
    }
}