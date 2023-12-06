#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    long long power=1;
    for(int i=1;i<=N;i++){
        int x=pow(10,9);
        power=(power*i)%(x+7);
    }
    cout<<power<<endl;
}