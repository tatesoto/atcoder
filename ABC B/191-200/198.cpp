#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    string S;
    cin>>S;
    string T=S;
    reverse(all(T));
    rep(i,20){
        if(S==T){
            out("Yes");
            return 0;
        }
        S="0"+S;
        T+="0";
    }
    out("No");
}