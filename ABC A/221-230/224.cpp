#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S;
    cin>>S;
    ll n=S.size();
    if(S.substr(n-2)=="er"){
        cout<<"er"<<endl;
    }
    else{
        cout<<"ist"<<endl;
    }
}