#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> a(N),b(N);
    rep(i,N) cin>>a.at(i);
    rep(i,N) cin>>b.at(i);
    vector<bool> aj(N,false),bj(N,false);
    aj.at(0)=true;
    bj.at(0)=true;
    for(ll i=0;i<N-1;i++){
        if(aj.at(i)){
            if(abs(a.at(i)-a.at(i+1))<=K){
                aj.at(i+1)=true;
            }
            if(abs(a.at(i)-b.at(i+1))<=K){
                bj.at(i+1)=true;
            }
        }
        if(bj.at(i)){
            if(abs(b.at(i)-a.at(i+1))<=K){
                aj.at(i+1)=true;
            }
            if(abs(b.at(i)-b.at(i+1))<=K){
                bj.at(i+1)=true;
            }
        }
    }
    if(aj.at(N-1)||bj.at(N-1)){
        out("Yes");
    }
    else{
        out("No");
    }
}