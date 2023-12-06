#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N,K,A;
    cin>>N>>K>>A;
    cout<<(A+K-2)%N+1<<endl;
}