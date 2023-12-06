#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S;
    cin>>S;
    string maxS=S;
    string minS=S;
    for(ll i=0;i<S.size();i++){
        char s=S.at(0);
        for(ll j=0;j<S.size()-1;j++){
            S.at(j)=S.at(j+1);
        }
        S.at(S.size()-1)=s;
        if(maxS<S){
            maxS=S;
        }
        if(minS>S){
            minS=S;
        }
    }
    cout<<minS<<endl;
    cout<<maxS<<endl;
}