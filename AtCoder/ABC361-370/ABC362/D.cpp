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
    ll N, M;cin>>N>>M;
    vector<ll> A(N);
    rep(i, N) cin>>A[i];
    Network G(N);
    rep(i, M) {
        ll a, b, c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back({b, c+A[b]});
        G[b].push_back({a, c+A[a]});
    }
    vector<ll> ans(N, -1);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({A[0], 0});
    while(!pq.empty()) {
        auto [cost, now] = pq.top();pq.pop();
        if(ans[now] != -1) continue;
        ans[now] = cost;
        for(auto [next, next_cost] : G[now]) {
            if(ans[next] == -1) {
                pq.push({cost + next_cost, next});
            }
        }
    }
    for (int i = 1; i < int(ans.size()); i++) {
        cout << ans[i] << " ";
        if(i == int(ans.size()) - 1) cout << endl;
    }
}