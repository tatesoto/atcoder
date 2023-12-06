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
    ll N,M;
    cin>>N>>M;
    vector<ll> b(M);
    for(ll i=0;i<M;i++){
        cin>>b.at(i);
    }

    vector<bool> judge(N+5,true);
    for(ll i=0;i<M;i++){
        judge.at(b.at(i))=false;
    }

    //無限大の値
    const ll INF=1LL<<60;
    //DP配列
    vector<ll> dp(100010,0);
    //初期条件
    dp.at(0)=1;
    //forループ

    for(ll i=1;i<=N;i++){
        if(judge.at(i)){
            if(judge.at(i-1)){
                dp.at(i)+=dp.at(i-1);
            }
            if(i>1 && judge.at(i-2)){
                dp.at(i)+=dp.at(i-2);
            }
        }
        else if(!judge.at(i-1)){
            cout<<0<<endl;
            return 0;
        }
        ll x=pow(10,9);
        dp.at(i)%=x+7;
    }
    cout<<dp.at(N)<<endl;
}