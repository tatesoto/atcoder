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
    ll N, Q;cin>>N>>Q;
    Grid G(N);
    rep(i, N) cin>>G[i];
    vector<ll> A(Q), B(Q), C(Q), D(Q);
    rep(i, Q) cin>>A[i]>>B[i]>>C[i]>>D[i];

    vector<vector<ll>> black(N, vector<ll>(N, 0));
    black[0][0] = (G[0][0] == 'B') ? 1:0;
    rep(i, N){
        rep(j, N){
            if(j == 0){
                black[i][j] = (G[i][j] == 'B') ? 1:0;
                continue;
            }
            black[i][j] = black[i][j-1];
            black[i][j] += (G[i][j] == 'B')? 1: 0;
        }
    }
    rep(j, N){
        rep(i, N){
            if(i == 0) continue;
            black[i][j] += black[i-1][j];
        }
    }

    auto cntB = [&](ll r, ll c){
        if(r < 0 || c < 0) return 0LL; 
        ll rr = r%N; ll qr = r/N;
        ll rc = c%N; ll qc = c/N;
        ll res = 0;
        res += qr*qc*black[N-1][N-1];
        res += qr*black[N-1][rc];
        res += qc*black[rr][N-1];
        res += black[rr][rc];
        return res;
    };

    auto query = [&](ll a, ll b, ll c, ll d){
        ll res = 0;
        res += cntB(c, d);
        res -= cntB(c, b-1) + cntB(a-1, d);
        res += cntB(a-1, b-1);
        return res;
    };

    rep(i, Q) out(query(A[i], B[i], C[i], D[i]));
}