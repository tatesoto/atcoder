#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,X;
    cin>>N>>X;
    vector<vector<ll>> dp(N+1);
    dp.at(0).push_back(1);
    rep(i,N){
        ll L;
        cin>>L;
        rep(j,L){
            ll a;
            cin>>a;
            for(ll x:dp.at(i)){
                if(a*x>X){
                    continue;
                }
                dp.at(i+1).push_back(a*x);
            }
        }
    }
    ll count=0;
    rep(i,dp.at(N).size()){
        if(dp.at(N).at(i)==X){
            count++;
        }
    }
    out(count);
}