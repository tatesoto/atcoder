#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    string S;
    cin>>S;
    reverse(all(S));
    rep(i,S.size()){
        char x=S.at(i);
        if(x=='6'){
            S.at(i)='9';
        }
        else if(x=='9'){
            S.at(i)='6';
        }
    }
    out(S);
}