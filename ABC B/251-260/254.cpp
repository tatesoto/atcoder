#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    cin>>N;
    vector<vector<ll>> out(N,vector<ll>(1,1));
    for(ll i=1;i<N;i++){
        for(ll j=1;j<=i;j++){
            out.at(i).push_back(1);
        }
    }
    for(ll i=2;i<N;i++){
        for(ll j=1;j<i;j++){
            out.at(i).at(j)=out.at(i-1).at(j-1)+out.at(i-1).at(j);
        }
    }
    for(ll i=0;i<N;i++){
        for(ll j=0;j<=i;j++){
            cout<<out.at(i).at(j);
            if(i==j){
                cout<<endl;
            }
            else{
                cout<<" ";
            }
        }
    }
}