#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    N%=100;
    if(N<=9){
        cout<<"0"<<N<<endl;
        return 0;
    }
    cout<<N<<endl;
}