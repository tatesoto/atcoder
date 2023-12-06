#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool move(ll now,ll from,ll future,ll to){
    if((to-from)<(future-now)){
        return true;
    }
    else{
        return false;
    }
}
int main() {
    ll N;
    cin>>N;
    vector<vector<ll>> data(N+10,vector<ll>(3));
    for(ll i=0;i<N;i++){
        for(ll j=0;j<3;j++){
            cin>>data.at(i).at(j);
        }
    }
    
}