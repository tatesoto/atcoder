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
    ll N;cin>>N;
    Graph G(N);
    rep(i, N){
        ll c;cin>>c;
        rep(j, c){
            ll p;cin>>p;p--;
            G[i].push_back(p);
        }
    }
    queue<ll> q;
    vector<ll> dist(N, -1);
    q.push(0);
    dist.at(0) = 0;
    while (!q.empty()){
        auto pos = q.front();q.pop();
        for(auto nx:G[pos]){
            if(chmax(dist.at(nx), dist.at(pos) + 1)) q.push(nx);
        }
    }
    vector<vector<ll>> ans(N);
    rep(i, N){
        if(dist.at(i) < 0) continue;
        ans[dist.at(i)].push_back(i);
    }
    for(int i=N-1;i>0;i--){
        if(ans.at(i).empty()) continue;
        for(auto x:ans[i]){
            cout<<x+1<<" ";
        }
    }
    cout<<"\n";
}
