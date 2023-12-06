#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll H,W,N;
    cin>>H>>W>>N;
    map<ll,vector<ll>> x,y;
    vector<ll> xN(N),yN(N);
    rep(i,N){
        ll a,b;
        cin>>a>>b;
        x[a].push_back(i);
        y[b].push_back(i);
    }
    ll count1=1,count2=1;
    for(auto v:x){
        for(auto l:v.second){
            xN.at(l)=count1;
        }
        count1++;
    }
    for(auto v:y){
        for(auto l:v.second){
            yN.at(l)=count2;
        }
        count2++;
    }
    rep(i,N){
        out(xN.at(i)<<" "<<yN.at(i));
    }
}