#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    string S;
    while(N>0){
        if(N%2==1){
            S+="A";
        }
        S+="B";
        N/=2;
    }
    reverse(all(S));
    rep(i,S.size()){
        cout<<S.at(i);
    }
    cout<<endl;
}