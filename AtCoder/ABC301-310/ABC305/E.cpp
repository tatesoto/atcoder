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
using Graph = vector<vector<int>>;
using Network = vector<vector<pair<ll,ll>>>;
using P = pair<ll,ll>;

int main() {
    int N, M;cin>>N>>M;
    int K;cin>>K;
    Graph G(N);
    rep(i, M){
        ll a, b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> p(K), h(K);
    rep(i, K) cin>>p.at(i)>>h.at(i), p.at(i)--;
    vector<int> dist(N, -1);
    priority_queue<P> pq;
    rep(i, K){
        pq.push({h.at(i), p.at(i)});
        dist.at(p.at(i)) = h.at(i);
    }
    while(!pq.empty()){
        auto pr = pq.top();pq.pop();
        int pos = pr.second;
        int cost = pr.first;
        if(dist.at(pos) != cost) continue;
        for(int next:G[pos]){
            if(chmax(dist.at(next), dist.at(pos) - 1)){
                pq.push({dist.at(next), next});
            }
        }
    }
    vector<int> ans;
    rep(i, N){
        if(dist.at(i) >= 0){
            ans.push_back(i+1);
        }
    }
    out(ans.size());
    rep(i, ans.size()){
        cout<<ans.at(i)<<" ";
    }
    cout<<"\n";
}