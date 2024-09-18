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
    auto count_less_or_equal = [&](vector<ll> &v, ll id, ll x) -> ll {
        if(id == int(v.size())) return 0LL;
        return distance(v.begin()+id, upper_bound(v.begin()+id, v.end(), x));
    };
    auto count_more_or_equal = [&](vector<ll> &v, ll x) {
        return distance(lower_bound(all(v), x), v.end());
    };
    ll N, Q;cin>>N>>Q;
    vector<ll> left, right;
    rep(i, N) {
        ll a;cin>>a;
        right.push_back(a);
    }
    sort(all(right));
    vector<pair<pair<ll,ll>,ll>> BK(Q);
    rep(i, Q) {
        ll B, K;cin>>B>>K;
        BK[i] = {{B, K}, i};
    }
    sort(all(BK));
    ll now_id = 0;
    vector<ll> ans(Q);
    rep(i, Q) {
        ll b = BK[i].first.first;
        ll k = BK[i].first.second;
        ll id = BK[i].second;
        while(now_id < N && right[now_id] < b) {
            left.push_back(right[now_id]);
            now_id++;
        }
        ll ok = 1e9;
        ll ng = -1;
        while(abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            ll cnt = count_more_or_equal(left, b-mid) + count_less_or_equal(right, now_id, b+mid);
            if(cnt >= k) {
                ok = mid;
            }
            else {
                ng = mid;
            }
        }
        ans[id] = ok;
        // cout << i << endl;
        // for (int i = 0; i < int(left.size()); i++) {
        //     cout << left[i] << " ";
        //     if(i == int(left.size()) - 1) cout << endl;
        // }
        // for (int i = now_id; i < int(right.size()); i++) {
        //     cout << right[i] << " ";
        //     if(i == int(right.size()) - 1) cout << endl;
        // }

    }
    for (int i = 0; i < int(ans.size()); i++) {
        cout << ans[i] << endl;
    }
}