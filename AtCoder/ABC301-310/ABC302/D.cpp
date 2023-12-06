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

int main() {
    ll N, M;cin>>N>>M;
    ll D;cin>>D;
    vector<ll> a(N), b(M), mb(M);
    rep(i, N) cin>>a.at(i);
    rep(i, M){
        cin>>b.at(i);
        mb.at(i) = -b.at(i);
    }
    sort(all(a));
    sort(all(mb));
    ll ans = -1;
    rep(i, N){
        auto iter = lower_bound(all(mb), - D - a.at(i));
        ll nb = *iter;
        if(abs(a.at(i) + nb) <= D){
            chmax(ans, a.at(i) - nb);
        }
    }
    out(ans);
}