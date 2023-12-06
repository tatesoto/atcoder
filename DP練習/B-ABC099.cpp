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
    //無限大の値
    const ll INF=1LL<<60;
    //DP配列
    vector<ll> dp(100010,INF);
    //初期条件
    dp.at(0)=0;
    //forループ
    for(ll i=1;i<=N;i++){
        dp.at(i)=i;
        ll to=i;
        ll x=6;
        while(x<=i){
            ll from=i-x;
            ll volume=1;
            chmin(dp.at(to),dp.at(from)+volume);
            x*=6;
        }
        x=9;
        while(x<=i){
            ll from=i-x;
            ll volume=1;
            chmin(dp.at(to),dp.at(from)+volume);
            x*=9;
        }
    }
    cout<<dp.at(N)<<endl;
}