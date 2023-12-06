#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,P,Q,R;
    cin>>N>>P>>Q>>R;
    vector<ll> data(N);
    rep(i,N) cin>>data.at(i);
    set<ll> S;
    S.insert(0);
    ll sum=0;
    rep(i,N){
        sum+=data.at(i);
        S.insert(sum);
    }
    for(auto x:S){
        if(S.count(x+P)&&S.count(x+P+Q)&&S.count(x+P+Q+R)){
            out("Yes");
            return 0;
        }
    }
    out("No");
}