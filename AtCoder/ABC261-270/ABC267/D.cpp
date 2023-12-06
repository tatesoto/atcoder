#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
const ll INF=1LL<<60;

//aよりbの方が大きかったらaをbに置き換える
bool chmax(ll &a,ll b){
    if(a<b){
        a=b;
        return true;
    }
    else{
        return false;
    }
}

int main() {
    ll N,M;
    cin>>N>>M;
    vector<ll> data(N);
    rep(i,N){
        cin>>data.at(i);
    }
    vector<vector<ll>> dp(N+5,vector<ll>(M+5,-INF));
    dp.at(1).at(1)=data.at(0);
    dp.at(1).at(0)=0;
    for(ll i=0;i<N+5;i++){
        dp.at(i).at(0)=0;
    }
    for(ll i=1;i<N;i++){
        for(ll j=0;j<=i;j++){
            if(j>M){
                continue;
            }
            if(j==M){
                dp.at(i+1).at(j)=dp.at(i).at(j);
                break;
            }
            dp.at(i+1).at(j+1)=max(dp.at(i).at(j+1),dp.at(i).at(j)+(j+1)*data.at(i));
        }
    }
    out(dp.at(N).at(M));
}