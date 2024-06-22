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
    vector<ll> l(M), d(M), k(M), c(M), A(M), B(M);
    rep(i, M) cin>>l[i]>>d[i]>>k[i]>>c[i]>>A[i]>>B[i], A[i]--, B[i]--;
    struct Edge {
        ll l, d, k, c, to;
    };
    
    vector<vector<Edge>> G(N);
    rep(i, M) {
        G[B[i]].push_back({l[i], d[i], k[i], c[i], A[i]});
    }
    auto floor = [&](ll l, ll d, ll k, ll x){
        if(x < l) return -INF;
        return min((x-l)/d, k-1)*d+l;
    };
    vector<ll> f(N, -INF);
    f[N-1] = INF;
    priority_queue<pair<ll,ll>> pq;
    pq.push({f[N-1], N-1});
    while(!pq.empty()) {
        auto [t, pos] = pq.top();
        pq.pop();
        if(f[pos] < t) continue;
        for(auto p:G[pos]) {
            auto [l, d, k, c, next] = p;
            ll nt = t - c;
            if(chmax(f[next], floor(l, d, k, nt))) {
                pq.push({f[next], next});
            }
        }
    }
    rep(i, N-1) {
        if(f[i] == -INF) out("Unreachable");
        else out(f[i]);
    }
}