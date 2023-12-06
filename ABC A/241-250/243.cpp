#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll V,A,B,C;
    cin>>V>>A>>B>>C;
    ll v=V%(A+B+C);
    string ans;
    if(v<A){
        ans="F";
    }
    else if(v<A+B){
        ans="M";
    }
    else{
        ans="T";
    }
    cout<<ans<<endl;
}