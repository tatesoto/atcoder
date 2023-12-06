#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s;
    cin>>s;
    vector<char> S(s.size());
    for(ll i=0;i<s.size();i++){
        S.at(i)=s.at(i);
    }
    sort(S.begin(),S.end());
    for(ll i=0;i<S.size();i++){
        cout<<S.at(i);
    }
    cout<<endl;
}