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
    Graph G(N, vector<ll>(N, INF));
    Graph A(N, vector<ll>(N, INF));
    rep(i, N) {
        rep(j, N) {
            cin >> A[i][j];
            G[i][j] = A[i][j];
        }
    }
    vector<vector<bool>> edges(N, vector<bool>(N, true));
    rep(i, N) edges[i][i] = false;
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                if(chmin(G[i][j], G[i][k] + G[k][j])) {
                    edges[i][j] = false;
                    edges[j][i] = false;
                }
            }
        }
    }
    ll sum = 0;
    rep(i, N) {
        rep(j, N) {
            if(A[i][j] != G[i][j]) {
                out(-1);
                return 0;
            }
            else {
                sum += (edges[i][j]) ? G[i][j] :0;
            }
        }
    }
    out(sum);
}
