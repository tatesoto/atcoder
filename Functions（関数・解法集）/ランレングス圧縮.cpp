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

/* encode: ランレングス圧縮を行う
*/
vector<pair<char, ll>> encode(const string& str) {
    ll n = (ll)str.size();
    vector<pair<char, ll>> ret;
    for (ll l = 0; l < n;) {
        ll r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

/* decode: ランレングス圧縮の復元を行う
*/
string decode(const vector<pair<char, ll>>& code) {
    string ret = "";
    for (auto p : code) {
        for (ll i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}

int main() {
    string S;cin>>S;
    vector<pair<char,ll>> v;
    v=encode(S);
    for(auto p:v){
        cout<<p.first<<" "<<p.second<<" ";
    }
    cout<<endl;
    out(decode(v));
}