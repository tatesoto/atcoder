#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<string> S(N);
    rep(i,N) cin>>S.at(i);
    vector<vector<ll>> slot(10,vector<ll>(10,0));
    rep(i,N){
        rep(j,10){
            ll x=S.at(i).at(j)-'0';
            slot.at(x).at(j)++;
        }
    }
    ll ans=1<<23;
    rep(i,10){
        ll sum=0;
        rep(j,10){
            ll x=slot.at(i).at(j);
            if(x!=0){
                sum=max(sum,j+10*(x-1));
            }
        }
        ans=min(ans,sum);
    }
    out(ans);
}