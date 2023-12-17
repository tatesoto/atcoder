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
    ll A, B, Q;cin>>A>>B>>Q;
    vector<ll> s(A+1, -INF), t(B+1, -INF);
    rep(i, A) cin>>s[i+1];
    rep(i, B) cin>>t[i+1];
    s.push_back(INF);
    t.push_back(INF);
    vector<ll> X(Q);
    rep(i, Q) cin>>X[i];

    auto near_by = [&](ll x, vector<ll> &v){
        ll idx = lower_bound(all(v), x) - v.begin();
        vector<ll> p = {v[idx-1], v[idx]};
        return p;
    };

    auto query = [&](ll x){
        ll ans = INF;
        auto p1 = near_by(x, s);
        rep(i, 2){
            auto p2 = near_by(p1[i], t);
            ll d1 = abs(x-p1[i]) + abs(p1[i]-p2[0]);
            ll d2 = abs(x-p1[i]) + abs(p1[i]-p2[1]);
            chmin(ans, min(d1, d2));
        }
        auto q1 = near_by(x, t);
        rep(i, 2){
            auto q2 = near_by(q1[i], s);
            ll d1 = abs(x-q1[i]) + abs(q1[i]-q2[0]);
            ll d2 = abs(x-q1[i]) + abs(q1[i]-q2[1]);
            chmin(ans, min(d1, d2));
        }
        return ans;
    };
    rep(i, Q) out(query(X[i]));
}
