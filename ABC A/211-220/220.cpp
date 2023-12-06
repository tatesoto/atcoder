#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll A,B,C;
    cin>>A>>B>>C;
    for(ll i=A;i<=B;i++){
        if(i%C==0){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}