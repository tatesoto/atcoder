#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<pair<ll,string>> p(N);
    rep(i,N){
        cin>>p.at(i).second>>p.at(i).first;
    }
    sort(all(p));
    reverse(all(p));
    out(p.at(1).second);
}