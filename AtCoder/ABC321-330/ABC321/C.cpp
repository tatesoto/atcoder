#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

int main() {
    ll K;cin>>K;
    vector<ll> a;
    for(ll bit = 2; bit < (1<<10); bit++){
        vector<ll> use;
        for(ll i = 9; i >= 0; i--){
            if(bit & (1 << i)) use.push_back(i);
        }
        ll n = 0;
        for(auto x:use){
            n *= 10;
            n += x;
        }
        a.push_back(n);
    }
    sort(all(a));
    out(a[K-1]);
}