#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll K;
    cin>>K;
    if(K<60){
        if(K<9){
            cout<<21<<":0"<<K<<endl;
            return 0;
        }
        cout<<21<<":"<<K<<endl;
    }
    else{
        ll k=K%60;
        if(k<9){
            cout<<22<<":0"<<k<<endl;
            return 0;
        }
        cout<<22<<":"<<k<<endl;
    }
}