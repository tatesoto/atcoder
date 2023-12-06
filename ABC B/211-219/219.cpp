#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<string> data(4);
    for(ll i=1;i<=3;i++){
        cin>>data.at(i);
    }
    string T;
    cin>>T;
    for(ll i=0;i<T.size();i++){
        cout<<data.at(T.at(i)-'0');
    }
    cout<<endl;
}