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
#define ull unsigned long long

int main() {
    ll xa, ya, xb, yb, xc, yc;cin>>xa>>ya>>xb>>yb>>xc>>yc;
    ull dxab = abs(xa-xb);
    ull dyab = abs(ya-yb);
    ull dxbc = abs(xb-xc);
    ull dybc = abs(yb-yc);
    ll cnt = 0;
    bool judge = false;
    if((xa-xb)*(xb-xc) > 0 && (ya))
    if(dxab != 0) cnt++;
    if(dyab != 0) cnt++;
    if(dxbc != 0) cnt++;
    if(dybc != 0) cnt++;
    out(dxab+dyab+dxbc+dybc+cnt*2-1);
}