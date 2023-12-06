#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<vector<int>> candy(2,vector<int>(N));
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin>> candy.at(i).at(j);
        }
    }
    int max_sum=0;
    for(int i=0;i<N;i++){
        int sum=0;
        for(int j=0;j<=i;j++){
            sum+=candy.at(0).at(j);
        }
        for(int k=i;k<N;k++){
            sum+=candy.at(1).at(k);
        }    
        max_sum=max(sum,max_sum);
    }
    cout <<max_sum<<endl;
}