#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll D,G;
    cin>>D>>G;
    vector<vector<ll>> data(D,vector<ll>(2));
    for(ll i=0;i<D;i++){
        cin>>data.at(i).at(0)>>data.at(i).at(1);
    }
    //ansを半無限に初期化
    ll ans=1<<30;
    //全完した問題で、bit全探索
    for(int bit=0;bit<(1<<D);bit++){
        //sumで点数の総和を、countで問題数を管理
        ll sum=0,count=0;
        for(int i=0;i<D;i++){
            if(bit & (1<<i)){
                //i番目を全完したときの点数と問題数をメモ
                sum+=data.at(i).at(0)*100*(i+1)+data.at(i).at(1);
                count+=data.at(i).at(0);
            }
        }
        //全完でGを越えたときは、問題数を現状の最小値と比較
        if(sum>=G){
            ans=min(ans,count);
        }
        //全完でGを越えなかったときは、点数が大きい方から順に解いていく
        else{
            for(ll i=D-1;i>=0;i--){
                //すでに全完しているところは排除
                if(bit & (1<<i)){
                    continue;
                }
                //まだ解いていない点数の問題を、Gを越えるまで高い方から埋めていく
                else{
                    for(ll j=0;j<data.at(i).at(0);j++){
                        if(sum>=G){
                            break;
                        }
                        sum+=100*(i+1);
                        count++;
                    }
                }
            }
            //問題数を現状の最小値と比較
            ans=min(ans,count); 
        }
    }
    cout<<ans<<endl;
}