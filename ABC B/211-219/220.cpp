#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll K;
    cin>>K;
    string A,B;
    cin>>A>>B;
    ll a=0;
    ll b=0;
    for(ll i=0;i<A.size();i++){
        ll x=A.at(i)-'0';
        a+=x;
        if(i==A.size()-1){
            break;
        }
        a*=K;
    }
    for(ll i=0;i<B.size();i++){
        ll x=B.at(i)-'0';
        b+=x;
        if(i==B.size()-1){
            break;
        }
        b*=K;
    }

    cout<<a*b<<endl;
}