#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll X,Y;
    cin>>X>>Y;
    ll count=0;
    while(X+10*count<Y){
        count++;
    }
    cout<<count<<endl;
}