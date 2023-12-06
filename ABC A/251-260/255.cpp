#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll R,C;
    cin>>R>>C;
    vector<vector<ll>> data(2,vector<ll>(2));
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            cin>>data.at(i).at(j);
        }
    }
    cout<<data.at(R-1).at(C-1)<<endl;
}