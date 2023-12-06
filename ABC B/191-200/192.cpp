#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    string S;
    cin>>S;
    for(ll i=0;i<S.size();i++){
        char x=S.at(i);
        if(i%2==0 && 'A'<=x && x<='Z'){
            out("No");
            return 0;
        }
        else if(i%2==1 && 'a'<=x && x<='z'){
            out("No");
            return 0;
        }
    }
    out("Yes");
}