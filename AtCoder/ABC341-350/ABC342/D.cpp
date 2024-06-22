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
    vector<ll> sq;
    for(ll i = 2; i*i <= 200000; i++) {
        sq.push_back(i*i);
    }
    ll N;cin>>N;
    map<ll,ll> mp;
    rep(i, N) {
        ll a;cin>>a;
        if(a == 0) {
            mp[0]++;
            continue;
        }
        for(auto x:sq) {
            while(a % x == 0) {
                a /= x;
            }
        }
        mp[a]++;
    }
    ll cnt = 0;
    for(auto p:mp) {
        auto [x, c] = p;
        if(x == 0) {
            cnt += c*(c-1)/2;
            cnt += c*(N-c);
        }
        else {
            cnt += c*(c-1)/2;
        }
    }
    out(cnt);
}