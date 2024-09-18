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
    vector<vector<vector<ll>>> A(N, vector<vector<ll>>(N, vector<ll>(N)));
    rep(i, N) {
        rep(j, N) {
            rep(k, N) {
                cin>>A[i][j][k];
            }
        }
    }
    vector<vector<vector<ll>>> sum(N+1, vector<vector<ll>>(N+1, vector<ll>(N+1)));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                sum[i][j][k] = sum[i][j][k-1] + A[i-1][j-1][k-1];
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                sum[i][j][k] += sum[i][j-1][k];
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                sum[i][j][k] += sum[i-1][j][k];
            }
        }
    }
    auto get_sum = [&](ll lx, ll rx, ll ly, ll ry, ll lz, ll rz) {
        return sum[rx][ry][rz] - sum[lx][ry][rz] - sum[rx][ly][rz] - sum[rx][ry][lz] + sum[lx][ly][rz] + sum[lx][ry][lz] + sum[rx][ly][lz] - sum[lx][ly][lz];
    };
    ll Q;cin>>Q;
    rep(i, Q) {
        ll lx, rx, ly, ry, lz, rz;cin>>lx>>rx>>ly>>ry>>lz>>rz;
        lx--;ly--;lz--;
        out(get_sum(lx, rx, ly, ry, lz, rz));
    }
}
