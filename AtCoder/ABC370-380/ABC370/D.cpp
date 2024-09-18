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
    ll H, W;cin>>H>>W;
    ll Q;cin>>Q;
    vector<ll> R(Q), C(Q);
    rep(i, Q) {
        cin>>R[i]>>C[i];
        R[i]--;C[i]--;
    }
    vector<set<ll>> wallr(H), wallc(W);
    rep(i, H) {
        rep(j, W) {
            wallr[i].insert(j);
            wallc[j].insert(i);
        }
    }
    ll ans = H*W;
    auto query = [&](ll r, ll c) {
        if (wallr[r].count(c)) {
            wallr[r].erase(c);
            wallc[c].erase(r);
            ans--;
            return ans;
        }
        auto it = wallr[r].lower_bound(c);
        if (it != wallr[r].end()) {
            wallr[r].erase(it);
            wallc[*it].erase(r);
            ans--;
        }
        it = wallr[r].lower_bound(c);
        if (it != wallr[r].begin()) {
            it--;
            wallr[r].erase(it);
            wallc[*it].erase(r);
            ans--;
        }
        it = wallc[c].lower_bound(r);
        if (it != wallc[c].end()) {
            wallc[c].erase(it);
            wallr[*it].erase(c);
            ans--;
        }
        it = wallc[c].lower_bound(r);
        if (it != wallc[c].begin()) {
            it--;
            wallc[c].erase(it);
            wallr[*it].erase(c);
            ans--;
        }
        return ans;
    };
    rep(i, Q) {
        query(R[i], C[i]);
    }
    out(ans);
}
