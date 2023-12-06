#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    int x=pow(K-1,N-1);
    cout<<K*x<<endl;
}