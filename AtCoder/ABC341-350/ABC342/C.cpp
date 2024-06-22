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
    string S;cin>>S;
    ll Q;cin>>Q;
    vector<char> c(Q), d(Q);
    rep(i, Q) cin>>c[i]>>d[i];
    vector<char> converter(26);
    rep(i, 26) converter[i] = 'a'+i;
    rep(i, Q) {
        rep(j, 26) {
            if(converter[j] == c[i]) converter[j] = d[i];
        }
    }
    rep(i, N) {
        S[i] = converter[S[i]-'a'];
    }
    out(S);

}