#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll S;
    cin>>S;
    ll sum=S;
    S=S/100+(S%100)*10;
    sum+=S;
    S=S/100+(S%100)*10;
    sum+=S;
    cout<<sum<<endl;
}