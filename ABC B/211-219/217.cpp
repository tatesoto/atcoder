#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    map<string,bool> data;
    data["ABC"]=true;
    data["ARC"]=true;
    data["AGC"]=true;
    data["AHC"]=true;
    for(ll i=0;i<3;i++){
        string x;
        cin>>x;
        data[x]=false;
    }
    for(auto p:data){
        if(p.second){
            cout<<p.first<<endl;
        }
    }
}