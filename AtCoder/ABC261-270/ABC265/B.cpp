#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N,M,T;
    cin>>N>>M>>T;
    vector<ll> room(N);
    for(ll i=1;i<=N-1;i++){
        cin>>room.at(i);
    }
    map<ll,ll> vonus;
    ll sum=T;
    bool judge=true;
    if(M==0){
        for(ll i=1;i<=N-1;i++){
            sum-=room.at(i);
        }
        if(sum<=0){
            judge=false;
        }
    }
    else{
        for(ll i=0;i<M;i++){
            ll x,y;
            cin>>x>>y;
            vonus[x]=y;
        }
        for(ll i=1;i<=N-1;i++){
            if(vonus.count(i)){
                sum+=vonus.at(i);
            }
            sum-=room.at(i);
            if(sum<=0){
                judge=false;
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