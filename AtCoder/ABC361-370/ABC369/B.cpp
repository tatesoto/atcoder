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
    vector<ll> L, R;
    rep(i, N) {
        ll a;cin>>a;
        char c;cin>>c;
        if(c == 'L') {
            L.push_back(a);
        } else {
            R.push_back(a);
        }
    }
    ll ans = 0;
    rep(i, L.size()-1) {
        ans += abs(L[i+1] - L[i]);
    }
    rep(i, R.size()-1) {
        ans += abs(R[i+1] - R[i]);
    }
    out(ans);
}
