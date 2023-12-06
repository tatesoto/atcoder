#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N;cin>>N;
    ll M;cin>>M;
    vector<ll> a(N+1, 0);
    rep(i, N) cin>>a.at(i+1);
    vector<set<ll>> vs(M + 1);
    for(ll i=1;i<=N;i++){
        ll l = (-a.at(i) + i - 1)/i;
        if(a.at(i) >= 0) l = 1;
        ll r = (N - a.at(i) + i - 1)/i;
        if(a.at(i) >= N) r = 1;
        chmin(r, M+1);
        for(ll j=l;j<r;j++){
            ll y = a.at(i) + i*j;
            vs.at(j).insert(y);
        }
    }
    rep(i, M){
        ll ans = 0;
        for(auto x:vs[i+1]){
            if(x == ans) ans++;
            else break;
        }
        out(ans);
    }
}