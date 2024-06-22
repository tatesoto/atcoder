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
    ll N, T;cin>>N>>T;
    vector<ll> A(T);
    rep(i, T) cin>>A[i];
    vector<vector<bool>> sheet(N, vector<bool>(N));
    auto to_xy = [&](ll x) {
        return make_pair(x/N, x%N);
    };
    auto is_bingo = [&](ll x, ll y) {
        rep(i, N) {
            if(sheet[i][y] == false) break;
            if(i == N-1) return true;
        }
        rep(i, N) {
            if(sheet[x][i] == false) break;
            if(i == N-1) return true;
        }
        if(x == y) {
            rep(i, N) {
                if(sheet[i][i] == false) break;
                if(i == N-1) return true;
            }
        }
        if(x == N-y-1) {
            rep(i, N) {
                if(sheet[i][N-i-1] == false) break;
                if(i == N-1) return true;
            }
        }
        return false;
    };
    rep(i, T) {
        auto [x, y] = to_xy(A[i]-1);
        sheet[x][y] = true;
        if(is_bingo(x, y)) {
            out(i+1);
            return 0;
        }
    }
    out(-1);

}