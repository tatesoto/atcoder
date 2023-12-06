#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,Q;
    cin>>N>>Q;
    map<ll,vector<ll>> data;
    rep(i,N){
        ll x;
        cin>>x;
        data[x].push_back(i+1);
    }
    vector<ll> ans(Q);
    rep(i,Q){
        ll x,k;
        cin>>x>>k;
        if(data.count(x)){
            if(data[x].size()>=k){
                ans.at(i)=data[x].at(k-1);
            }
            else{
                ans.at(i)=-1;
            }
        }
        else{
            ans.at(i)=-1;
        }
    }
    for(auto x:ans){
        out(x);
    }
}