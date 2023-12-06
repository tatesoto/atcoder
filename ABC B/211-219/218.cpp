#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<ll> data(26);
    for(ll i=0;i<26;i++){
        cin>>data.at(i);
    }
    for(ll i=0;i<26;i++){
        cout<<(char)('a'+data.at(i)-1);
    }
    cout<<endl;
}