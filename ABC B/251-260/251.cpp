#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N,W;
    cin>>N>>W;
    vector<ll> data(N+5,0);
    for(ll i=1+1;i<=N+1;i++){
        cin>>data.at(i);
    }
    set<ll> good;
    for(ll i=0;i<=N+1;i++){
        for(ll j=i+1;j<=N+1;j++){
            for(ll k=j+1;k<=N+1;k++){
                ll sum;
                sum=data.at(i)+data.at(j)+data.at(k);
                if(sum<=W){
                    good.insert(sum);
                }
            }
        }
    }
    cout<<good.size()<<endl;
}