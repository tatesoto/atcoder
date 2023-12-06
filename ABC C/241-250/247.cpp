#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)



int main() {
    ll N;
    cin>>N;
    string S="1";
    for(ll i=2;i<=N;i++){
        S=S+" "+to_string(i)+" "+S;
    }
    out(S);
}