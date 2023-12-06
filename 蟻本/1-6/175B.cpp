#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin>>N;
    vector<ll> L;
    for(ll i=0;i<N;i++){
        ll x;
        cin>>x;
        L.push_back(x);
    }
    ll count=0;
    ll n=L.size();
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            for(ll k=j+1;k<n;k++){
                ll a,b,c;
                a=L.at(i);
                b=L.at(j);
                c=L.at(k);
                if((a-b)*(b-c)*(c-a)!=0 && a+b>c && b+c>a && c+a>b){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
}