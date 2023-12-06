#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll H,W,X,Y;
    cin>>H>>W>>X>>Y;
    vector<string> a(H+1);
    a.at(0)="x";
    rep(i,H){
        string s;
        cin>>s;
        a.at(i+1)="0"+s;
    }
    ll count=1;
    for(ll i=X-1;i>=1;i--){
        if(a.at(i).at(Y)=='#'){
            break;
        }
        count++;
    }
    for(ll i=X+1;i<=H;i++){
        if(a.at(i).at(Y)=='#'){
            break;
        }      
        count++;
    }
    for(ll i=Y-1;i>=1;i--){
        if(a.at(X).at(i)=='#'){
            break;
        }
        count++;
    }
    for(ll i=Y+1;i<=W;i++){
        if(a.at(X).at(i)=='#'){
            break;
        }
        count++;
    }
    out(count);
}