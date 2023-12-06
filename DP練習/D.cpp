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
    vector<vector<ll>> data(N,vector<ll>(2));
    for(ll i=0;i<N;++i){
        cin>>data.at(i).at(0);
        cin>>data.at(i).at(1); 
    }
    //無限大の値
    const ll INF=1LL<<60;
    //DP配列
    vector<vector<ll>> dp(110,vector<ll>(W+5,0));
    //初期条件
    //forループ
    for(ll i=0;i<N;++i){
        for(ll j=0;j<=W;++j){
            ll to=i+1;
            ll from=i;
            ll volume=data.at(i).at(1);
            ll w=data.at(i).at(0);
            if(j-w>=0){
                chmax(dp.at(to).at(j),dp.at(from).at(j-w)+volume);               
            }
            chmax(dp.at(i+1).at(j),dp.at(i).at(j));
        }
    }
    cout<<dp.at(N).at(W)<<endl;
}