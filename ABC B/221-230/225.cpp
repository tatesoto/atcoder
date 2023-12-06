#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    map<ll,ll> data;
    for(ll i=0;i<2*(N-1);i++){
        ll x;
        cin>>x;
        if(data.count(x)){
            data[x]++;
        }
        else{
            data[x]=1;
        }
    }
    ll maxc=0;
    for(ll i=0;i<data.size();i++){
        maxc=max(maxc,data[i]);
    }
    if(maxc==N-1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}