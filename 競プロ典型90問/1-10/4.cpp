#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll H,W;
    cin>>H>>W;
    vector<vector<ll>> data(H,vector<ll>(W));
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            cin>>data.at(i).at(j);
        }
    }
    vector<ll> h(W);
    vector<ll> w(H);
    for(ll i=0;i<W;i++){
        ll sum=0;
        for(ll j=0;j<H;j++){
            sum+=data.at(j).at(i);
        }
        h.at(i)=sum;
    }
    for(ll i=0;i<H;i++){
        ll sum=0;
        for(ll j=0;j<W;j++){
            sum+=data.at(i).at(j);
        }
        w.at(i)=sum;
    }
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            ll s;
            s=w.at(i)+h.at(j)-data.at(i).at(j);
            cout<<s;
            if(j==W-1){
                cout<<endl;
                break;
            }
            cout<<" ";
        }
    }
}