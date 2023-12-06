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
    ll N1, N2, M;cin>>N1>>N2>>M;
    ll N = N1 + N2;
    Graph G(N);
    rep(i, M){
        ll a, b;cin>>a>>b;a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> dist(N, -1);
    queue<ll> q;
    q.push(0);
    q.push(N-1);
    dist.at(0) = 0;
    dist.at(N-1) = 0;
    while(!q.empty()){
        ll pos = q.front();q.pop();
        for(auto next:G[pos]){
            if(dist.at(next) >= 0) continue;
            dist.at(next) = dist.at(pos) + 1;
            q.push(next);
        }
    }
    ll d1 = -1;
    ll d2 = -1;
    rep(i, N1) chmax(d1, dist.at(i));
    rep(i, N2) chmax(d2, dist.at(N1+i));
    out(d1+d2+1);
}