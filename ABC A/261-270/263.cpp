#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<ll> data(5);
    for(ll i=0;i<5;i++){
        cin>>data.at(i);
    }
    sort(data.begin(),data.end());
    if(data.at(0)==data.at(1)&&data.at(2)==data.at(3)&&data.at(2)==data.at(4)&&data.at(0)!=data.at(2)){
        cout<<"Yes"<<endl;
        return 0;
    }
    reverse(data.begin(),data.end());
    if(data.at(0)==data.at(1)&&data.at(2)==data.at(3)&&data.at(2)==data.at(4)&&data.at(0)!=data.at(2)){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
}