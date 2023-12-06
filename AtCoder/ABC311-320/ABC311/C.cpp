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
    ll N;cin>>N;
    Graph G(N);
    rep(i, N){
        ll a;cin>>a;a--;
        G[i].push_back(a);
    }
    vector<bool> seen(N, false);
    rep(i, N){
        if(seen.at(i)) continue;
        deque<ll> dq;
        ll cur = i;
        while(true){
            if(seen[cur]){
                while(dq[0] != cur){
                    dq.pop_front();
                }
                out(dq.size());
                while(!dq.empty()){
                    ll x = dq.front();dq.pop_front();
                    out(x+1);
                }
                return 0;
            }
            dq.push_back(cur);
            seen[cur] = true;
            cur = G[cur][0];
        }
    }
}