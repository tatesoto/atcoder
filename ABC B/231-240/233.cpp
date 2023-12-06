#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll L,R;
    cin>>L>>R;
    string S;
    cin>>S;
    for(ll i=0;i<L-1;i++){
        cout<<S.at(i);
    }
    for(ll i=R-1;i>=L-1;i--){
        cout<<S.at(i);
    }
    for(ll i=R;i<S.size();i++){
        cout<<S.at(i);
    }
    cout<<endl;
}