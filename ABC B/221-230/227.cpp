#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    set<ll> S;
    for(ll a=1;a<200;a++){
        for(ll b=1;b<200;b++){
            ll square=4*a*b+3*a+3*b;
            S.insert(square);
        }
    }
    ll count=0;
    for(ll i=0;i<N;i++){
        ll x;
        cin>>x;
        if(!S.count(x)){
            count++;
        }
    }
    cout<<count<<endl;
}