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
    Graph G(N);
    rep(i, N-1){
        ll p;cin>>p;p--;
        G[p].push_back(i+1);
    }
    vector<ll> dp(N, -1);
    rep(i, M){
        ll x,y;cin>>x>>y;x--;
        chmax(dp.at(x), y);
    }
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll pos = q.front();q.pop();
        for(auto next:G[pos]){
            chmax(dp.at(next), dp.at(pos)-1);
            q.push(next);
        }
    }
    ll ans = 0;
    rep(i, N) if(dp.at(i) >= 0) ans++;
    out(ans);
}