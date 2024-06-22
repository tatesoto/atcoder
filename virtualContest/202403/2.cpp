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
    string S;cin>>S;
    auto judge = [&](string s) {
        if(s.size() % 2 == 1) return false;
        for(ll i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[i + s.size() / 2]) return false;
        }
        return true;
    };
    ll n = S.size();
    rep(i, n) {
        S.pop_back();
        if(judge(S)) {
            out(S.size());
            return 0;
        }
    }
}
