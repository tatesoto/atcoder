#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    cin>>N;
    vector<string> sei(N+5),mei(N+5);
    for(ll i=0;i<N;i++){
        cin>>sei.at(i)>>mei.at(i);
    }
    set<string> S;
    vector<string> adana(N+5);
    for(ll i=0;i<N;i++){
        S.clear();
        for(ll j=0;j<N;j++){
            if(i==j){
                continue;
            }
            S.insert(sei.at(j));
            S.insert(mei.at(j));
        }
        if(S.count(sei.at(i)) && S.count(mei.at(i))){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}