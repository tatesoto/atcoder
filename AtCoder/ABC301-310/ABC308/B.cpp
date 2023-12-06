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
    vector<string> C(N);
    rep(i, N) cin>>C.at(i);
    map<string, ll> mp;
    vector<string> D(M);
    vector<ll> P(M);
    rep(i, M) cin>>D.at(i);
    ll p0; cin>> p0;
    rep(i, M) cin>>P.at(i);
    rep(i, M){
        mp[D.at(i)] = P.at(i);
    }
    ll ans = 0;
    rep(i, N){
        if(!mp.count(C.at(i))) ans += p0;
        else ans += mp[C.at(i)];
    }
    out(ans);
}