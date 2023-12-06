#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N,X;
    cin>>N>>X;
    ll x=X/N;
    if(X%N==0){
        x=X/N-1;
    }
    cout<<(char)('A'+x)<<endl;
}