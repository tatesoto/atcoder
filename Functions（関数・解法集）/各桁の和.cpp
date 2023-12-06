#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll Sum(ll n){
    ll res=0;
    while(n>0){
        res += n%10;
        n/=10;
    }
    return res;
}

int main(){
    ll N;
    cin>> N;
    cout << Sum(N) <<endl;
}