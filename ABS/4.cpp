#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> data(N);
    for(int i=0;i<N;i++){
        cin>>data.at(i);
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<N;j++){
            if(data.at(j)%2==1){
                cout <<i<<endl;
                return 0;
            }
            else{
                data.at(j)/=2;
            }
        }
    }
}