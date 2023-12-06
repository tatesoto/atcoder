#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N,K;
    cin>>N>>K;
    vector<int> taste(N);
    vector<int> like(K);
    for(ll i=0;i<N;i++){
        cin>>taste.at(i);
    }
    for(ll i=0;i<K;i++){
        cin>>like.at(i);
    }
    ll maxtaste=0;
    for(ll i=0;i<N;i++){
        ll x=taste.at(i);
        maxtaste=max(maxtaste,x);
    }
    bool judge=false;
    for(ll i=0;i<N;i++){
        ll x=taste.at(i);
        if(x==maxtaste){
            for(ll j=0;j<K;j++){
                if(like.at(j)==i+1){
                    judge=true;
                }
            }
        }
    }
    if(judge){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}