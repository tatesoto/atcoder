#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    set<string> S;
    S.insert("H");
    S.insert("2B");
    S.insert("3B");
    S.insert("HR");
    rep(i,4){
        string x;
        cin>>x;
        S.erase(x);
    }
    if(S.size()==0){
        out("Yes");
    }
    else{
        out("No");
    }
}