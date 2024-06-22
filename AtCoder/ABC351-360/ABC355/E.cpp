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
    ll N, L, R;cin>>N>>L>>R;
    auto division_cnt_by_2 = [&](ll x) -> pair<ll,ll> {
        if(x == 0) {
            return {0, 61};
        }
        ll cnt = 0;
        ll y = x;
        while(y % 2 == 0) {
            y /= 2;
            cnt++;
        }
        return {y, cnt};
    };
    vector<pair<ll,ll>> ans;
    ll nowl = L;
    while(nowl < R) {
        auto [x, cnt] = division_cnt_by_2(nowl);
        for(ll l = cnt; ; l--) {
            ll y = (1LL << l) * (x+1);
            if(y <= R) {
                ans.push_back({nowl, y});
                nowl = y;
                break;
            }
            x *= 2;
        }
    }
    ll ans = 0;
    for(auto [l, r] : ans) {
        cout << "? " << l << " " << r+1 << endl;
        ans += (r-l+1);
    }
}