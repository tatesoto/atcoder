#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    set<string> S;
    vector<ll> T;
    for(ll i=1;i<=N;i++){
        string s;
        ll t;
        cin>>s>>t;
        if(!S.count(s)){
            S.insert(s);
            T.push_back(100000*t+100000-i);
        }
    }
    sort(all(T));
    reverse(all(T));
    ll n=T.at(0);
    n=-(n%100000)+100000;
    out(n);
}