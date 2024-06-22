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
    string S, T;cin>>S>>T;
    auto f = [&](string s) {
        ll n = s.size();
        map<char, ll> mp;
        vector<ll> v;
        rep(i, n) {
            if(mp.count(s[i])) {
                v.push_back(mp[s[i]]);
            } else {
                mp[s[i]] = mp.size();
                v.push_back(mp[s[i]]);
            }
        }
        return v;
    };
    if(f(S) == f(T)) out("Yes");
    else out("No");
}
