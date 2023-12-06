#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    map<string,ll> cand;
    for(ll i=0;i<N;i++){
        string x;
        cin>>x;
        if(!cand.count(x)){
            cand[x]=1;
        }
        else{
            cand[x]++;
        }
    }
    string ans;
    ll maxe=0;
    for(auto p:cand){
        string k=p.first;
        ll v=p.second;
        if(v>maxe){
            maxe=v;
            ans=k;
        }      
    }
    cout<<ans<<endl;
}