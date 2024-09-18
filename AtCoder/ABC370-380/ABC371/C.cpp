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
    ll N, MG;cin>>N>>MG;
    vector<vector<bool>> G(N, vector<bool>(N, false));
    rep(i, MG) {
        ll A, B;cin>>A>>B;
        A--;B--;
        G[A][B] = G[B][A] = true;
    }
    ll MH;cin>>MH;
    vector<vector<bool>> H(N, vector<bool>(N, false));
    rep(i, MH) {
        ll C, D;cin>>C>>D;
        C--;D--;
        H[C][D] = H[D][C] = true;
    }
    vector<vector<ll>> A(N, vector<ll>(N, 0));
    rep(i, N) {
        for(int j = i+1; j < N; j++) {
            cin>>A[i][j];
            A[j][i] = A[i][j];
        }
    }
    vector<ll> perm(N);
    iota(all(perm), 0);
    ll ans = INF;
    do {
        ll cnt = 0;
        rep(i, N) {
            for(int j = i+1; j < N; j++) {
                if(G[i][j] != H[perm[i]][perm[j]]) {
                    cnt += A[perm[i]][perm[j]];
                }
            }
        }
        chmin(ans, cnt);
    } while(next_permutation(all(perm)));
    out(ans);
}
