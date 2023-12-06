#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll H,W;
    cin>>H>>W;
    vector<vector<ll>> data(H,vector<ll>(W));
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            cin>>data.at(i).at(j);
        }
    }
    for(ll i=0;i<W;i++){
        for(ll j=0;j<H;j++){
            cout<<data.at(j).at(i);
            if(j<H-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}