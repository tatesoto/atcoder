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
    ll N, M;cin>>N>>M;
    vector<map<ll,ll>> G(N);
    rep(i, M){
        ll a, b, c;cin>>a>>b>>c;a--;b--;
        G[a][b] = c;
        G[b][a] = c;
    }
    vector<ll> v(N);
    iota(all(v), 0);
    ll ans = -1;
    do{ 
        ll res = 0;
        rep(i, N-1){
            if(!G[v[i]].count(v[i+1])) break;
            res += G[v[i]][v[i+1]];
        }
        chmax(ans, res);
    }while(next_permutation(all(v)));
    out(ans);
}