#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    string S;cin>>S;
    vector<ll> even(S.size() + 1, 0);
    rep(i, S.size()){
        ll n = S.at(i) - '0';
        ll x = even.at(i);
        ll m = 1 << n;
        x ^= m;
        even.at(i + 1) = x;
    }
    map<ll, ll> count;
    rep(i, even.size()){
        count[even.at(i)]++;
    }
    ll cnt = 0;
    for(auto p:count){
        ll x = p.first;
        ll y = p.second;
        ll z = y*(y-1)/2;
        cnt += z;
    }
    out(cnt);
}