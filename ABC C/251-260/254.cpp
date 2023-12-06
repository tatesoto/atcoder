#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> a(N);
    vector<vector<ll>> b(K);
    for(ll i=0;i<N;i++){
        cin>>a.at(i);
        b.at(i%K).push_back(a.at(i));
    }
    for(ll i=0;i<K;i++){
        sort(b.at(i).rbegin(),b.at(i).rend());
    }
    sort(all(a));
    vector<ll> c;
    for(ll i=0;i<N;i++){
        c.push_back(b.at(i%K).back());
        b.at(i%K).pop_back();
    }
    if(a==c){
        out("Yes");
    }
    else{
        out("No");
    }
}