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
    ll N,W;
    cin>>N>>W;
    vector<ll> weight(110),value(110);
    for(ll i=0;i<N;i++){
        cin>>weight.at(i)>>value.at(i);
    }
    //無限大の値
    const ll INF=1LL<<60;
    //DP配列
    vector<vector<ll>> dp(110,vector<ll>(101000,INF));
    //初期条件
    dp.at(0).at(0)=0;
    //forループ
    for(ll i=0;i<N;i++){
        for(ll j=0;j<100100;j++){
            ll to=i+1;
            ll from=i;
            ll volume=weight.at(i);
            ll v=value.at(i);
            if(j-v>=0){
                chmin(dp.at(to).at(j),dp.at(from).at(j-v)+volume);
            }
            chmin(dp.at(i+1).at(j),dp.at(i).at(j));
        }
    }
    ll ans=0;
    for(ll j=0;j<100100;j++){
        if(dp.at(N).at(j)<=W){
            ans=j;
        }
    }
    cout<<ans<<endl;
}