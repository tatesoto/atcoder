#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>> N;
    vector<int> data(N);
    for(int i=0;i<N;i++){
        cin>>data.at(i);
    }
    map<int,int> datamap;
    for(int x:data){
        datamap[x]=0; //.atは存在しないとerror
    }
    for(int x:data){
        datamap.at(x)++;
    }
    int max_datamap=0;
    int ans;
    for(int x:data){
        if(max_datamap<datamap.at(x)){
            max_datamap=datamap.at(x);
            ans=x;
        }
    }
    cout<<ans<<" "<<max_datamap<<endl;
}