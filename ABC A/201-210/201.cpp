#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    vector<ll> a(3);
    rep(i,3){
        cin>>a.at(i);
    }
    sort(all(a));
    if(a.at(1)*2==a.at(0)+a.at(2)){
        out("Yes");
    }
    else{
        out("No");
    }
}