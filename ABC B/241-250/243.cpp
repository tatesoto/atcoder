#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    cin>>N;
    vector<ll> A(N),B(N);
    for(ll i=0;i<N;i++){
        cin>>A.at(i);
    }
    for(ll i=0;i<N;i++){
        cin>>B.at(i);
    }
    ll count1=0;
    for(ll i=0;i<N;i++){
        if(A.at(i)==B.at(i)){
            count1++;
        }
    }
    set<ll> a;
    for(ll i=0;i<N;i++){
        a.insert(A.at(i));
    }
    ll count2=0;
    for(ll i=0;i<N;i++){
        if(a.count(B.at(i))){
            count2++;
        }
    }
    cout<<count1<<endl;
    cout<<count2-count1<<endl;
}