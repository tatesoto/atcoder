#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll H,W;
    cin>>H>>W;
    vector<vector<char>> data(H,vector<char>(W));
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            cin>>data.at(i).at(j);
        }
    }
    ll sx,sy;
    ll gx,gy;
    bool judge=false;
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            if(data.at(i).at(j)=='o'){
                sx=j;
                sy=i;
                data.at(i).at(j)='-';
                judge=true;
                break;
            }
        }
        if(judge){
            break;
        }
    }
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            if(data.at(i).at(j)=='o'){
                gx=j;
                gy=i;
            }
        }
    }
    ll d=abs(sx-gx)+abs(sy-gy);
    cout <<d <<endl;
}