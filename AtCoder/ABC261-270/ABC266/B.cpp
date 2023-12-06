#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    N=N%998244353;
    if(N<0){
        N=N+998244353;
    }
    cout<<N<<endl;
}