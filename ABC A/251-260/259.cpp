#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N,M,X,T,D;
    cin>>N>>M>>X>>T>>D;
    if(X<=M){
        cout<<T<<endl;
        return 0;
    }
    else{
        cout<<T-D*X+D*M<<endl;
    }
}