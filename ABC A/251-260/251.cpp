#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string so;
    cin>>so;
    string S=so;
    ll s=S.size();
    for(ll i=1;i<6/s;i++){
        S+=so;
    }
    cout<<S<<endl;
}