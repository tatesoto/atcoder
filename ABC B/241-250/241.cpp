#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N,M;
    cin>>N>>M;
    vector<ll> pasta(N);
    for(ll i=0;i<N;i++){
        cin>>pasta.at(i);
    }
    vector<ll> length(M);
    for(ll i=0;i<M;i++){
        cin>>length.at(i);
    }

    for(ll i=0;i<M;i++){
        bool judge=true;
        for(ll j=0;j<N;j++){
            if(length.at(i)==pasta.at(j)){
                pasta.at(j)=-1;
                judge=false;
                break;
            }
        }
        if(judge){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}