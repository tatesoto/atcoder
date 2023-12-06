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
    int N, M;cin>>N>>M;
    Network G(N);
    vector<ll> H(N);
    const ll pot = 1LL<<32;
    rep(i, N) cin>>H.at(i);
    rep(i, M){
        int a, b;cin>>a>>b;
        a--,b--;
        if(H.at(a) < H.at(b)) swap(a, b);
        G[a].push_back({b, -(H.at(a) - H.at(b))});
        G[b].push_back({a, -2*(H.at(b) - H.at(a))});
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<ll> score(N, INF);
    score.at(0) = pot;
    pq.push({pot, 0});
    while(!pq.empty()){
        auto p = pq.top();pq.pop();
        int pos = p.second;
        ll d = p.first;
        if(d > score.at(pos)) continue;
        for(auto next_sc:G[pos]){
            int next = next_sc.first;
            ll sc = next_sc.second;
            if(chmin(score.at(next), d + sc)){
                pq.push({d + sc, next});
            }
        }
    }
    ll ans = -INF;
    rep(i, N){
        ll x = score.at(i);
        x -= pot;
        chmax(ans, -x);
    }
    out(ans);
}