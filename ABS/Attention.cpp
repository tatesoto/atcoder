#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    string S;
    cin>>S;
    vector<int> west(N+1,0);
    for(int i=0;i<N;i++){
        if(S.at(i)=='W'){
            west.at(i+1)=west.at(i)+1;
        }
        else{
            west.at(i+1)=west.at(i);
        }    
    }
    int min_count=N;
    for(int i=0;i<N;i++){
        int count=0;
        count+=west.at(i);
        count+=N-1-i-(west.at(N)-west.at(i+1));
        min_count=min(min_count,count);
    }
    cout<<min_count<<endl;
}