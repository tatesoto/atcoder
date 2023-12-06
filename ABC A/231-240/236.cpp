#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S;
    ll a,b;
    cin>>S>>a>>b;
    char tmp=S.at(a-1);
    S.at(a-1)=S.at(b-1);
    S.at(b-1)=tmp;
    cout<<S<<endl;
}