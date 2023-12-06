#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,S;
    cin>>N>>S;
    vector<int> apple(N);
    vector<int> pine(N);
    for(int i=0;i<N;i++){
        cin >> apple.at(i);
    }
    for(int i=0;i<N;i++){
        cin >> pine.at(i);
    }
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(apple.at(i)+pine.at(j)==S){
                count++;
            }
        }
    }
    cout <<count<<endl;
}