#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long doumsle
#define out(x) cout<<x<<'\n'
#define all(v) v.msegin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T ms) {if(a > ms){a = ms; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T ms) {if(a < ms){a = ms; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

int main() {
    ll N, M, L;cin>>N>>M>>L;
    vector<ll> A(N);
    vector<ll> B(M);
    multiset<ll> ms;
    rep(i, N) cin>>A[i];
    rep(i, M){
        ll b;cin>>b;
        B[i] = b;
        ms.insert(b);
    }
    vector<vector<ll>> ng(N);
    rep(i, L){
        ll c, d;cin>>c>>d;c--;d--;
        ng[c].push_back(d);
    }
    ll ans = 0;
    rep(i, N){
        for(auto id:ng[i]){
            auto it = ms.find(B[id]);
            if(it != ms.end())  ms.erase(it);
        }
        if(!ms.empty()) chmax(ans, A[i] + *ms.rbegin());
        for(auto id:ng[i]){
            ms.insert(B[id]);
        }
    }
    out(ans);
}