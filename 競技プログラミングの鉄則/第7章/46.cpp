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
    vector<ll> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    vector<ll> v(N);
    auto dist = [&](ll i, ll j) {
        return (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
    };
    auto score = [&](vector<ll> &v) {
        ld res = 0;
        rep(i, N) {
            res += sqrt(dist(v[i], v[i+1]));
        }
        return res;
    };
    v[0] = 0;
    vector<bool> used(N, false);
    used[0] = true;
    rep(i, N-1) {
        ll min_dist = INF;
        ll next = -1;
        rep(j, N) {
            if(used[j]) continue;
            if(chmin(min_dist, dist(v[i], j))) {
                next = j;
            }
        }
        v[i+1] = next;
        used[next] = true;
    }
    v.push_back(0);
    ld now = score(v);
    chrono::system_clock::time_point start = chrono::system_clock::now();
    mt19937_64 rnd(chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count());
    while(true) {
        ll t = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count();
        if (t >= 950) break;
        ll l = 1 + rnd() % (N-1);
        ll r = 2 + rnd() % (N-1);
        if(l > r) swap(l, r);
        if(l == r) continue;
        vector<ll> nv = v;
        reverse(nv.begin() + l, nv.begin() + r);
        ld n_score = score(nv);

        ld T = 30.0 - 28.0 * t / 950.0;
        ld P = exp((now - n_score) / T);
        if(P > (ld)rnd() / (ld)rnd.max()) {
            v = nv;
            now = n_score;
        }
    }
    for(int i = 0; i <= N; i++) {
        out(v[i] + 1);
    }


}
