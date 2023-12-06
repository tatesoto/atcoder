#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<ll> T(N);
    vector<vector<ll>> need(N);
    rep(i,N){
        cin>>T.at(i);
        ll K;
        cin>>K;
        rep(j,K){
            ll A;
            cin>>A;
            need.at(i).push_back(A);
        }
    }
    vector<bool> judge(N,false);
    judge.at(N-1)=true;
    for(ll i=N-1;i>=0;i--){
        if(judge.at(i)){
            for(auto x:need.at(i)){
                judge.at(x-1)=true;
            }
        }
    }
    ll ans=0;
    rep(i,N){
        if(judge.at(i)){
            ans+=T.at(i);
        }
    }
    out(ans);
}