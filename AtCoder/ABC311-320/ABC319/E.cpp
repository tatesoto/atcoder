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
    ll N, X, Y;cin>>N>>X>>Y;
    vector<ll> P(N-1), T(N-1);
    rep(i, N-1) cin>>P[i]>>T[i];
    ll Q;cin>>Q;
    vector<ll> q(Q);
    rep(i, Q) cin>>q[i];
    const ll g = 24*7*5;
    vector<ll> time(g, 0);
    rep(i, g){
        ll now = i;
        ll t = 0;
        rep(j, N-1){
           ll next = (now + P[j] - 1)/P[j]*P[j];
           t += next - now + T[j];
           now = next + T[j];
        }
        time[i] = t;
    }
    rep(qi, Q){
        out(q[qi] + X + Y + time[(q[qi] + X)%g]);
    }
}
