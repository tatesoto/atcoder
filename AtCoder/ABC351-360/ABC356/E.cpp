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
    vector<ll> A(N);
    ll maxA = 0;
    map<ll,ll> mp;
    rep(i, N) {
        cin>>A[i];
        maxA = max(maxA, A[i]);
        mp[A[i]]++;
    }
    sort(all(A));
    auto cnt = [&] (ll l, ll r) {
        auto itr1 = lower_bound(all(A), l);
        auto itr2 = lower_bound(all(A), r);
        return itr2 - itr1;
    };
    ll ans = 0;
    vector<ll> cntSum(maxA+1, 0);
    for(int i = 1; i <= maxA; i++) {
        if(!mp.count(i)) continue;
        for(int j = 0; i*j <= maxA; j++) {
            cntSum[i] += j*cnt(i*j, i*(j+1));
        }
    }
    rep(i, N) {
        ans += cntSum[A[i]];
    }
    for(auto x: mp) {
        ans -= x.second*(x.second+1)/2;
    }
    out(ans);
}