#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll A,B,K;
    cin>>A>>B>>K;
    ll count=0;
    while(A<B){
        A*=K;
        count++;
    }
    cout<<count<<endl;
}