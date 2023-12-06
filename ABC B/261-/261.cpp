#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<vector<int>> data(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char x;
            cin>>x;
            if(x=='W'){
                data.at(i).at(j)=1;
            }
            else if(x=='L'){
                data.at(i).at(j)=-1;
            }
            else{
                data.at(i).at(j)=0;
            }
        }
    }
    bool judge=true;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(data.at(i).at(j)+data.at(j).at(i)!=0){
                judge=false;
            }
        }
    }
    if(judge){
        cout<<"correct"<<endl;
    }
    else{
        cout<<"incorrect"<<endl;
    }
}