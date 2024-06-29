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

ll solve() {
    ll n;cin>>n;
    if(n==0) return 1;
    vector<ll> d(n);
    rep(i, n) cin>>d[i];
    ll cnt = 0;
    vector<ll> target = {2, 0, 2, 0};
    rep(i, n) {
        bool judge = true;
        if(i+3>=n) break;
        rep(j, 4) {
            if(d[i+j] != target[j]) judge = false;
        }
        cnt += judge;
    }
    out(cnt);
    return 0;
}

int main() {
    while(!solve()) {}
    return 0;
}