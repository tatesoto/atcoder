#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<ll> a(N),b(N);
    rep(i,N){
        cin>>a.at(i);
    }
    rep(i,N){
        cin>>b.at(i);
    }
    ll left=0;
    ll right=10000;
    rep(i,N){
        left=max(left,a.at(i));
        right=min(right,b.at(i));
    }
    out(max(right-left+1,0LL));
}