#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    vector<ll> h(3);
    vector<ll> w(3);
    ll hsum=0,wsum=0;
    rep(i,3){
        cin>>h.at(i);
        hsum+=h.at(i);
    }
    rep(i,3){
        cin>>w.at(i);
        wsum+=w.at(i);
    }
    if(hsum!=wsum){
        out(0);
        return 0;
    }
    ll count=0;
    for(ll i=1;i<30;i++){
        for(ll j=1;j<30;j++){
            for(ll k=1;k<30;k++){
                for(ll l=1;l<30;l++){
                    if(w.at(0)-i-k>0 && w.at(1)-j-l>0 && h.at(0)-i-j>0 && h.at(1)-k-l>0&& h.at(2)-(w.at(0)+w.at(1)-i-j-k-l)>0){
                        count++;
                    }
                }
            }
        }
    }
    out(count);
}