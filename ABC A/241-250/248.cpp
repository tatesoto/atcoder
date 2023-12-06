#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S;
    cin>>S;
    set<ll> data;
    for(ll i=0;i<9;i++){
        data.insert(S.at(i)-'0');
    }
    for(ll i=0;i<10;i++){
        if(!data.count(i)){
            cout<<i<<endl;
            return 0;
        }
    }
}