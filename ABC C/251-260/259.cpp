#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S,T;
    cin>>S>>T;
    ll s=S.size();
    ll t=T.size();
    string ans="Yes";
    if(S!=T && s==t){
        ans="No";
    }
    for(ll i=0;i<200000-s;i++){
        S+="A";
    }
    ll k=0;
    for(ll i=0;i<T.size();i++){
        if(S.at(i-k)!=T.at(i)){
            if(i-k<2){
                ans="No";
                break;
            }
            else if(S.at(i-k-1)!=S.at(i-k-2)){
                ans="No";
                break;
            }
            else if(T.at(i)!=S.at(i-k-1)){
                ans="No";
                break;
            }
            else{
                k++;
            }
        }
    }
    cout<<ans<<endl;
}