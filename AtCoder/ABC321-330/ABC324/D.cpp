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
    ll N;cin>>N;
    vector<ll> mp(10, 0);
    rep(i, N){
        char c;cin>>c;
        mp[c-'0']++;
    }
    auto power = [&](ll x, ll n){
        ll res = 1;
        rep(i, n) res *= x;
        return res;
    };
    ll ssq = sqrt(power(10, N-1)) - 10;
    vector<ll> v;
    for(ll i = 0; i*i <= power(10, N);i++){
        ll n = i*i;
        v.push_back(n);
    }
    ll cnt = 0;
    for(auto x:v){
        vector<ll> res(10, 0);
        rep(i, N){
            ll c = x%10;
            res[c]++;
            x /= 10;
        }
        if(mp == res) cnt++;
    }
    out(cnt);
}