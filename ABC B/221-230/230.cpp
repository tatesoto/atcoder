#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S;
    cin>>S;
    vector<char> T(60);
    for(ll i=0;i<20;i++){
        T.at(3*i)='o';
        T.at(3*i+1)='x';
        T.at(3*i+2)='x';
    }
    ll check=-1;
    for(ll i=0;i<S.size();i++){
        if(S.at(i)=='o'){
            check=i;
            break;
        }
    }
    for(ll i=0;i<S.size();i++){
        ll j=30-check+i;
        if(S.at(i)!=T.at(j)){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}