#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N,Q;
    cin>>N>>Q;
    string S;
    cin>>S;
    vector<vector<ll>> data(Q,vector<ll>(2));
    for(ll i=0;i<Q;i++){
        cin>>data.at(i).at(0)>>data.at(i).at(1);
    }
    ll k=0;
    for(ll i=0;i<Q;i++){
        ll x=(data.at(i).at(1)-1-k+500000*N)%N;
        if(data.at(i).at(0)==1){
            ll y=data.at(i).at(1);
            k+=y;
        }
        else{
            cout<<S.at(x)<<endl;
        }
    }
}