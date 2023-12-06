#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string S;
    cin>>S;
    vector<char> s(S.size());
    for(ll i=0;i<S.size();i++){
        s.at(i)=S.at(i);
    }
    bool upper=false;
    bool lower=false;
    for(ll i=0;i<s.size();i++){
        if(islower(s.at(i))){
            lower=true;
        }
        else{
            upper=true;
        }
    }
    set<char> smap;
    for(ll i=0;i<s.size();i++){
        smap.insert(s.at(i));
    }
    bool judge=false;
    if(smap.size()==s.size()){
        judge=true;
    }
    if(upper && lower && judge){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}