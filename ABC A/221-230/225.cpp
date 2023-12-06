#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    set<char> data;
    for(ll i=0;i<3;i++){
        char x;
        cin>>x;
        data.insert(x);
    }
    ll n=data.size();
    if(n==1){
        cout<<1<<endl;
    }
    else if(n==2){
        cout<<3<<endl;
    }
    else{
        cout<<6<<endl;
    }
}