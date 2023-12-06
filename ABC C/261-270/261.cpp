#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    map<string,ll> data;
    vector<string> ans(N);
    for(ll i=0;i<N;i++){
        string x;
        cin>>x;
        if(data.count(x)){
            string y;
            ll n;
            n=data[x];
            y=x+"("+to_string(n)+")";
            ans.at(i)=y;
            data[x]++;
        }
        else{
            ans.at(i)=x;
            data[x]=1;
        }
    }
    for(auto z:ans){
        cout<<z<<endl;
    }
}