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
    rep(i, 3) {
        T[i] = T[i] - 'A' + 'a';
    }
    auto is_substr = [&](string s, string t) -> bool {
        ll n = s.size(), m = t.size();
        ll id = 0;
        rep(i, n) {
            if(s[i] == t[id]) {
                id++;
            }
            if(id == m) {
                return true;
            }
        }
        return false;
    };
    if(T[2] == 'x') {
        T.pop_back();
        if(is_substr(S, T)) {
            out("Yes");
        }
        else {
            out("No");
        }
    }
    else {
        if(is_substr(S, T)) {
            out("Yes");
        }
        else {
            out("No");
        }
    }
}