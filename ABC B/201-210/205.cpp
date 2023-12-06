#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;cin>>N;
    set<ll> a;
    rep(i,N){
        ll x; cin>>x;
        a.insert(x);
    }
    bool judge=true;
    if(a.size()!=N){
        judge=false;
    }
    rep(i,N){
        if(!a.count(i+1)){
            judge=false;
        }
    }
    if(judge) out("Yes");
    else out("No");
}