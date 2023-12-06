#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll L,R;
    string S;
    S="atcoder";
    cin>>L>>R;
    for(ll i=L-1;i<=R-1;i++){
        cout<<S.at(i);
    }
    cout<<endl;
}