#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N,A,B;
    cin>>N>>A>>B;
    vector<vector<char>> data(N*A,vector<char>(N*B,'.'));
    for(ll i=0;i<N*A;i++){
        for(ll j=0;j<N*B;j++){
            if((i/A+j/B)%2==1){
                data.at(i).at(j)='#';
            }
        }
    }
    for(ll i=0;i<N*A;i++){
        for(ll j=0;j<N*B;j++){
            cout<<data.at(i).at(j);
            if(j==N*B-1){
                cout<<endl;
            }
        }
    }
}