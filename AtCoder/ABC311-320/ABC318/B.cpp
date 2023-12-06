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
    vector<vector<bool>> check(101, vector<bool>(101, false));
    rep(i, N){
        ll a, b, c, d;cin>>a>>b>>c>>d;
        for(int j = a;j < b; j++){
            for(int k = c; k < d; k++){
                check[j][k] = true;
            }
        }
    }
    ll cnt = 0;
    rep(i, 101){
        rep(j, 101){
            if(check[i][j]) cnt++;
        }
    }
    out(cnt);
}
