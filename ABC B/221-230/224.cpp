#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll H,W;
    cin>>H>>W;
    vector<vector<ll>> data(H,vector<ll>(W));
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            cin>>data.at(i).at(j);
        }
    }
    bool judge=true;
    for(ll i1=0;i1<H-1;i1++){
        for(ll i2=i1+1;i2<H;i2++){
            for(ll j1=0;j1<W-1;j1++){
                for(ll j2=j1+1;j2<W;j2++){
                    if(data.at(i1).at(j1)+data.at(i2).at(j2)>data.at(i2).at(j1)+data.at(i1).at(j2)){
                        judge=false;
                    }
                }
            }
        }
    }
    if(judge){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}