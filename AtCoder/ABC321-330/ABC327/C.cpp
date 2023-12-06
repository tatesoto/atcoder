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
    ll n = 9;
    vector<vector<ll>> a(9, vector<ll>(9));
    rep(i, n) rep(j, n) cin>>a[i][j];
    bool judge = true;
    vector<bool> b(9, true);
    rep(i, n){
        vector<bool> c(9, false);
        rep(j, n){
            c[a[i][j]-1] = true;
        }
        rep(j, n){
            if(b[j] != c[j]) judge = false;
        }
    }
    rep(j, n){
        vector<bool> c(9, false);
        rep(i, n){
            c[a[i][j]-1] = true;
        }
        rep(i, n){
            if(b[i] != c[i]) judge = false;
        }
    }
    for(int i = 0; i < 9; i += 3){
        for(int j = 0; j < 9; j += 3){
            vector<bool> c(9, false);
            rep(di, 3){
                rep(dj, 3){
                    c[a[i+di][j+dj]-1] = true;
                }
            }
            rep(k, n){
                if(b[k] != c[k]) judge = false;
            }
        }
    }
    if(judge) out("Yes");
    else out("No");
}