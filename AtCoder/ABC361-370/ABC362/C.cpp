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
    vector<ll> l(N), r(N);
    rep(i, N) cin>>l[i]>>r[i];
    ll XnMax = 0;
    rep(i, N-1) XnMax += -l[i];
    ll XnMin = 0;
    rep(i, N-1) XnMin += -r[i];
    auto has_intersection = [&](ll l1, ll r1, ll l2, ll r2) {
        return max(l1, l2) <= min(r1, r2);
    };
    vector<ll> ans(N);
    if(!has_intersection(l[N-1], r[N-1], XnMin, XnMax)) {
        out("No");
        return 0;
    }
    out("Yes");
    if(l[N-1] <= XnMin) {
        ans[N-1] = XnMin;
        for(ll i = N-2; i >= 0; i--) {
            ans[i] = r[i];
        }
    }
    else {
        ans[N-1] = l[N-1];
        ll dif = l[N-1] - XnMin;
        for(ll i = N-2; i >= 0; i--) {
            if(dif > r[i] - l[i]) {
                ans[i] = l[i];
                dif -= r[i] - l[i];
            }
            else {
                ans[i] = r[i] - dif;
                dif = 0;
            }
        }
    }
    for (int i = 0; i < int(ans.size()); i++) {
        cout << ans[i] << " ";
        if(i == int(ans.size()) - 1) cout << endl;
    }
}