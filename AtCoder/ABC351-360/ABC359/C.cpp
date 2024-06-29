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
// const vector<ll> dx = {0, 1, 0, -1};
// const vector<ll> dy = {1, 0, -1, 0};

int main() {
    ll sx, sy, tx, ty;cin>>sx>>sy>>tx>>ty;
    if(sx > tx) {
        swap(sx, tx);
        swap(sy, ty);
    }
    if(ty < sy) {
        ty = -ty;
        sy = -sy;
    }
    if(((sx+sy) % 2 + 2) % 2 == 1) {
        sx--;
    }
    if(((tx+ty) % 2 + 2) % 2 == 1) {
        tx--;
    }
    ll ans = 0;
    ll dx = tx - sx;
    ll dy = ty - sy;
    if(dx <= dy) {
        ans = dy;
    }
    else {
        ans = dy + (dx-dy)/2;
    }
    out(ans);
}