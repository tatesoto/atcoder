#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N,X;
    cin>>N>>X;
    vector<ll> data(N+1);
    for(ll i=1;i<=N;i++){
        cin>>data.at(i);
    }
    vector<bool> judge(N+1,true);
    ll count=0;
    ll to=X;
    for(ll i=0;i<N;i++){
        if(judge.at(to)){
            count++;
            judge.at(to)=false;
            to=data.at(to);
        }
        else{
            break;
        }
    }
    cout<<count<<endl;
}