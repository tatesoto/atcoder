#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s,T;
    cin>>s>>T;
    string S=s;
    if(S==T){
        cout<<"Yes"<<endl;
        return 0;
    }
    for(ll i=0;i<S.size()-1;i++){
        S=s;
        char a,b;
        a=S.at(i);
        b=S.at(i+1);
        S.at(i)=b;
        S.at(i+1)=a;
        if(S==T){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}