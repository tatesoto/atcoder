#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    string S;
    cin>>S;
    vector<bool> split(7,false);
    set<ll> stand;
    rep(i,10){
        if(S.at(i)=='1'){
            stand.insert(i);
        }
    }
    if(S.at(0)=='1'){
        out("No");
        return 0;
    }
    else{
        if(S.at(3)=='0'){
            split.at(1)=true;
        }
        if(S.at(5)=='0'){
            split.at(5)=true;
        }
        if(S.at(4)=='0'){
            split.at(3)=true;
        }
        if(S.at(1)=='0' &&  S.at(7)=='0'){
            split.at(2)=true;
        }
        if(S.at(2)=='0' &&  S.at(8)=='0'){
            split.at(4)=true;
        }
        if(split.at(1)){
            if(stand.count(6)){
                 rep(i,10){
                    if(i==3||i==6){
                        continue;
                    }
                    if(stand.count(i)){
                        out("Yes");
                        return 0;
                    }
                 }   
            }
        }
        if(split.at(5)){
            if(stand.count(9)){
                 rep(i,10){
                    if(i==5||i==9){
                        continue;
                    }
                    if(stand.count(i)){
                        out("Yes");
                        return 0;
                    }
                 }   
            }
        }
        if(split.at(3)){
            if(stand.count(9)||stand.count(5)||stand.count(8)||stand.count(2)){
                if(stand.count(6)||stand.count(7)||stand.count(3)||stand.count(1)){
                    out("Yes");
                    return 0;
                }
            }
        }
        if(split.at(2)){
            if(stand.count(3)||stand.count(6)){
                 rep(i,10){
                    if(i==1||i==3||i==6||i==7){
                        continue;
                    }
                    if(stand.count(i)){
                        out("Yes");
                        return 0;
                    }
                 }   
            }
        }
        if(split.at(4)){
            if(stand.count(9)||stand.count(5)){
                 rep(i,10){
                    if(i==2||i==5||i==8||i==9){
                        continue;
                    }
                    if(stand.count(i)){
                        out("Yes");
                        return 0;
                    }
                 }   
            }
        }
        out("No");
    }
}