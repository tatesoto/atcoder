#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    string S;cin>>S;
    ll count=0;
    rep(i,7){
        if(S.at(i)=='a') S.at(i)='0';
        if(S.at(i)=='t') S.at(i)='1';
        if(S.at(i)=='c') S.at(i)='2';
        if(S.at(i)=='o') S.at(i)='3';
        if(S.at(i)=='d') S.at(i)='4';
        if(S.at(i)=='e') S.at(i)='5';
        if(S.at(i)=='r') S.at(i)='6';
    }
    rep(i,7){
        for(ll j=i+1;j<7;j++){
            if(S.at(i)>S.at(j)){
                count++;
            }
        }
    }
    out(count);
}