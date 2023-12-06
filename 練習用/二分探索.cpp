#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> data(N);
    for(ll i=0;i<N;i++){
        cin>>data.at(i);
    }
    for(ll i=0;i<N;i++){
        if(data.at(i)>=K){
            cout<<i<<endl;
            return 0;
        }
        else if(i==N-1){
            cout<<-1<<endl;
            return 0;
        }
    }
}