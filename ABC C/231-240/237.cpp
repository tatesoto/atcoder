#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    string S;
    cin>>S;
    ll count=0;
    rep(i,S.size()){
        if(S.at(i)=='a'){
            count++;
        }
        else{
            S=S.substr(count);
            break;
        }
    }
    ll Count=0;
    reverse(all(S));
    rep(i,S.size()){
        if(S.at(i)=='a'){
            Count++;
        }
        else{
            S=S.substr(Count);
            break;
        }
    }
    string T=S;
    reverse(all(T));
    if(S==T&&count<=Count){
        out("Yes");
    }
    else{
        out("No");
    }
}