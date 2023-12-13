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
    string S;cin>>S;
    vector<ll> l(Q), r(Q);
    rep(i, Q) cin >> l[i] >> r[i], l[i]--, r[i]--;
    vector<ll> cnt(N+1, 0);
    rep(i, N-1){
        if(S[i] == S[i+1]) cnt[i+1] = cnt[i] + 1;
        else cnt[i+1] = cnt[i];
    }
    auto query = [&](ll l, ll r){
        return cnt[r] - cnt[l];
    };
    rep(i, Q){
        out(query(l[i], r[i]));
    }
}