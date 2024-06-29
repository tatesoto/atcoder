#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
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
    ll N, K;cin>>N>>K;
    vector<vector<ll>> ab(5010, vector<ll>(5010, 0));
    rep(i, N) {
        ll a, b;cin>>a>>b;
        ab[a][b]++;
    }
    vector<vector<ll>> sumab(5020, vector<ll>(5020, 0));
    rep(i, 5010) {
        rep(j, 5010) {
            sumab[i][j+1] += sumab[i][j] + ab[i][j];
        }
    }
    rep(j, 5010) {
        rep(i, 5010) {
            sumab[i+1][j] += sumab[i][j];
        }
    }
    auto query = [&] (ll a, ll b, ll c, ll d) {
        return sumab[c+1][d+1] - sumab[c+1][b] - sumab[a][d+1] + sumab[a][b];
    };
    ll ans = 0;
    rep(i, 5010) {
        rep(j, 5010) {
            if(i+K >= 5010) break;
            chmax(ans, query(i, j, i+K, j+K));
        }
    }
    out(ans);
}