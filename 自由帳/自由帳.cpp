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
    ld n;cin>>n;
    vector<ld> a(n);
    rep(i, n) cin>>a[i];
    ld ave = 0;
    rep(i, n) ave += a[i];
    ave /= n;
    ld var = 0;
    rep(i, n) var += (a[i]-ave)*(a[i]-ave);
    var /= n-1;
    cout << "ave: " << ave << endl;
    cout << "var: " << var << endl;
}