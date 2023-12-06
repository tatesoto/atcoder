#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    ll x=1.08*N;
    if(x<206){
        out("Yay!");
    }
    else if(x==206){
        out("so-so");
    }
    else{
        out(":(");
    }
}