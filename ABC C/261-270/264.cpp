#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll H1,W1;
    cin>>H1>>W1;
    vector<vector<ll>> A(H1,vector<ll>(W1));
    for(ll i=0;i<H1;i++){
        for(ll j=0;j<W1;j++){
            cin>>A.at(i).at(j);
        }
    }
    ll H2,W2;
    cin>>H2>>W2;
    vector<vector<ll>> B(H2,vector<ll>(W2));
    for(ll i=0;i<H2;i++){
        for(ll j=0;j<W2;j++){
            cin>>B.at(i).at(j);
        }
    }
    for(ll bith=0;bith<(1<<H1);bith++){
        for(ll bitw=0;bitw<(1<<W1);bitw++){
            vector<int> hvec,wvec;
            for(ll i=0;i<H1;i++){
                if(bith & (1<<i)){
                    hvec.push_back(i+1);
                }
            }
            for(ll i=0;i<W1;i++){
                if(bitw & (1<<i)){
                    wvec.push_back(i+1);
                }
            }
            if(hvec.size()!=H2||wvec.size()!=W2){
                continue;
            }
            bool judge=true;
            for(ll i=0;i<H2;i++){
                for(ll j=0;j<W2;j++){
                    if(A.at(hvec.at(i)-1).at(wvec.at(j)-1)!=B.at(i).at(j)){
                        judge=false;
                    }
                }
            }
            if(judge){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}