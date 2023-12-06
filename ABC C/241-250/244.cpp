#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    set<ll> a;
    rep(i,2*N+1) a.insert(i+1);
    rep(i,N+1){
        ll x=*begin(a);
        out(x);
        a.erase(x);
        ll y;
        cin>>y;
        if(y==0){
            return 0;
        }
        a.erase(y);
    }
}