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

int main() {
    ll N,M;cin>>N>>M;
    Graph G(N+1);
    rep(i,M){
        ll a,b;cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll ans=0;
    for(ll i=1;i<=N;i++){
        ll cnt=0;
        for(auto x:G.at(i)){
            if(x<i){
                cnt++;
            }
        }
        if(cnt==1){
            ans++;
        }
    }
    out(ans);
}