#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll H,W;
    cin>>H>>W;
    vector<vector<bool>> judge(H+5,vector<bool>(W+5,false));
    vector<vector<char>> data(H+5,vector<char>(W+5));
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cin>>data.at(i).at(j);
        }
    }
    ll i=1,j=1;
    while(true){
        if(judge.at(i).at(j)){
            cout<<-1<<endl;
            return 0;
        }
        judge.at(i).at(j)=true;
        if(data.at(i).at(j)=='U'&&i!=1){
            i--;
        }
        else if(data.at(i).at(j)=='D'&&i!=H){
            i++;
        }
        else if(data.at(i).at(j)=='L'&&j!=1){
            j--;
        }
        else if(data.at(i).at(j)=='R'&&j!=W){
            j++;
        }
        else{
            break;
        }
    }
    cout<<i<<" "<<j<<endl;
}