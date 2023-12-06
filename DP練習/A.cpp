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
    vector<ll> data(N+5,0);
    for(ll i=1;i<=N;i++){
        cin>>data.at(i);
    }
    //無限大の値
    const ll INF=1LL<<60;
    //DP配列
    vector<ll> dp(100010,INF);
    //初期条件
    dp.at(0)=0;
    dp.at(1)=0;
    //forループ
    for(ll i=2;i<=N;i++){
        ll h=data.at(i);
        ll h1=data.at(i-1);
        ll h2=data.at(i-2);
        chmin(dp.at(i),dp.at(i-1)+abs(h-h1));
        chmin(dp.at(i),dp.at(i-2)+abs(h-h2));
    }
    cout<<dp.at(N)<<endl;
}