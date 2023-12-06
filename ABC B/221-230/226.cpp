#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    set<vector<ll>> ans;
    for(ll i=0;i<N;i++){
        ll L;
        cin>>L;
        vector<ll> data(L);
        for(ll j=0;j<L;j++){
            cin>>data.at(j);
        }
        ans.insert(data);
    }
    cout<<ans.size()<<endl;
}