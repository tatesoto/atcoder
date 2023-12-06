#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,X;
    cin>>N>>X;
    vector<ll> a;
    rep(i,N){
        ll x;
        cin>>x;
        if(x==X){
            continue;
        }
        else{
            a.push_back(x);
        }
    }
    for(ll i=0;i<a.size();i++){
        cout<<a.at(i);
        if(i!=a.size()-1){
            cout<<" ";
        }
    }
    cout<<endl;
}