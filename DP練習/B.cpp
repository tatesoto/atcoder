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
    ll N,K;
    cin>>N>>K;
    vector<ll> data(N+5);
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
        for(ll j=1;j<=K && i-j>=1;j++){
            ll to=i;
            ll from=i-j;
            ll volume=abs(data.at(i-j)-data.at(i));
            chmin(dp.at(to),dp.at(from)+volume);
        }
    }
    cout<<dp.at(N)<<endl;
}