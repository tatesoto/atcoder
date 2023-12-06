#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    cout<<"AGC0";
    if(N<=9){
        cout<<"0"<<N<<endl;;
    }
    else if(N<42){
        cout<<N<<endl;
    }
    else{
        cout<<N+1<<endl;
    }
}