#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int Y;
    cin>>Y;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N-i;j++){
            int sum;
            int k=N-i-j;
            sum=10000*i+5000*j+1000*k;
            if(sum==Y){
                cout<<i<<" "<<j<<" "<<k<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
}