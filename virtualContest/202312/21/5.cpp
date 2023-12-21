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
    ll cnt = 0;
    map<pair<ll,ll>, ll> mp;
    for(int i = 1; i <= N; i++){
        string s = to_string(i);
        ll f = s[0] - '0';
        ll b = s[s.size()-1] - '0';
        mp[{f,b}]++;
    }
    for(auto [p, c]:mp){
        ll f = p.first;
        ll b = p.second;
        cnt += c * mp[{b,f}];
    }
    out(cnt);
    
}
