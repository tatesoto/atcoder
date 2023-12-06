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

int main() {
    ll N;cin>>N;
    string S;cin>>S;
    vector<pair<char, ll>> judge = encode(S);
    ll ans = -1;
    bool stick = false;
    for(auto p:judge){
        if(p.first == '-') stick = true;
        if(p.first == 'o') chmax(ans, p.second);
    }
    if(stick) out(ans);
    else out(-1);
}