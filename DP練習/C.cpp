#include <bits/stdc++.h>
using namespace std;
#define ll long long

//aよりbの方が小さかったらaをbに置き換える
bool chmin(ll &a,ll b){
    if(a>b){
        a=b;
        return true;
    }
    else{
        return false;
    }
}
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

int main(){
    ll N;
    cin>>N;
    vector<vector<ll>> data(N+5,vector<ll>(3,0));
    for(ll i=1;i<=N;i++){
        cin>>data.at(i).at(0);
        cin>>data.at(i).at(1);
        cin>>data.at(i).at(2);
    }
    //無限大の値
    const ll INF=1LL<<60;
    //DP配列
    vector<vector<ll>> dp(100010,vector<ll>(3,0));
    //forループ
    for(ll i=1;i<=N+1;i++){
        ll to=i;
        ll from=i-1;
        for(ll j=0;j<3;j++){
            for(ll k=0;k<3;k++){
                if(k==j){
                    continue;
                }
                ll volume=data.at(i-1).at(k);
                chmax(dp.at(to).at(k),dp.at(from).at(j)+volume);
            }
        }

    }
    ll ans=0;
    for(ll i=0;i<3;i++){
        chmax(ans,dp.at(N+1).at(i));
    }
    cout<<ans<<endl;
}