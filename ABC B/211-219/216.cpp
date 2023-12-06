#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    vector<string> data(N);
    set<string> S;
    for(ll i=0;i<N;i++){
        string s,t;
        cin>>s>>t;
        s+=" ";
        s+=t;
        data.at(i)=s;
        S.insert(s);
    }
    if(data.size()==S.size()){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}