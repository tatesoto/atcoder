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
using P = pair<ll,ll>;

int main() {
    ll N, K;cin>>N>>K;
    map<ll,ll> mp;
    ll sum = 0;
    rep(i, N){
        ll a, b;cin>>a>>b;
        mp[a] += b;
        sum += b;
    }
    ll now = 0;
    for(auto p:mp){
        auto [a, b] = p;
        if(sum <= K) break;
        sum -= b;
        now = a;
    }
    out(now+1);
}