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
    ll N = 9;
    vector<vector<ll>> g(3, vector<ll>(3));
    rep(i, 3){
        rep(j, 3){
            cin>>g[i][j];
        }
    }
    vector<ll> v(9);
    iota(all(v), 0);
    ld allcnt = 0;
    ld cnt = 0;
    do{
        bool judge = true;
        vector<vector<bool>> check(3, vector<bool>(3, false));
        for(auto x:v){
            ll i = x/3;
            ll j = x%3;
            check[i][j] = true;
            if(check[(i+1)%3][j] && check[(i+2)%3][j] && g[(i+1)%3][j] == g[(i+2)%3][j]) judge = false;
            if(check[i][(j+1)%3] && check[i][(j+2)%3] && g[i][(j+1)%3] == g[i][(j+2)%3]) judge = false;
            if(i == j && check[(i+1)%3][(j+1)%3] && check[(i+2)%3][(j+2)%3] && g[(i+1)%3][(j+1)%3] == g[(i+2)%3][(j+2)%3]) judge = false;
            if(i + j == 2 && check[(i+1)%3][(j+2)%3] && check[(i+2)%3][(j+1)%3] && g[(i+1)%3][(j+2)%3] == g[(i+2)%3][(j+1)%3]) judge = false;
        }
        if(judge) cnt++;
        allcnt++;
    }while(next_permutation(all(v)));
    ld p = cnt/allcnt;
    cout<<fixed<<setprecision(16);
    out(p);
}
