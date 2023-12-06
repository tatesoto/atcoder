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

/**
 * トポロジカルソート
 * 頂点数をV、辺数をEとして O(V+E)
 */
vector<ll> topological_sort(const Graph& G){
  const ll n=G.size();
  vector<ll> in_cnt(n); // 各頂点の入次数
  // 各頂点の入次数をカウント
  for(ll v=0; v<n; v++){
    for(auto nv: G[v]){
      in_cnt[nv]++;
    }
  }
  // 入次数が0の頂点を始点としてqueueにpush（同時にresにもpush）
  vector<ll> res;
  queue<ll> q;
  for(ll v=0; v<n; v++){
    if(in_cnt[v]==0){
      q.push(v);
      res.push_back(v);
    }
  }
  // queueに入っている頂点から移動可能な頂点の入次数をデクリメントし、入次数が0になったものをqueueにpush
  while(!q.empty()){
    ll v=q.front(); q.pop();
    for(auto nv: G[v]){
      in_cnt[nv]--;
      if(in_cnt[nv]==0){
        q.push(nv);
        res.push_back(nv);
      }
    }
  }
  reverse(res.begin(), res.end()); // 入次数0の頂点を先頭にしたい場合
  return res;
}


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
    vector<ll> id = topological_sort(G);
    queue<ll> q;
    set<ll> st;
    q.push(0);
    while(!q.empty()){
        auto pos = q.front();q.pop();
        for(auto nx:G[pos]){
            if(!st.count(nx)){
                st.insert(nx);
                q.push(nx);
            }
        }
    }
    rep(i, id.size()){
        if(!st.count(id.at(i))) continue; 
        cout<<id.at(i)+1<<" ";
    }
    cout<<endl;
}
