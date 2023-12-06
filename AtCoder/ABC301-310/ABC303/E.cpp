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

Graph G;
vector<ll> depth;
void dfs_d(ll s, ll p){
    if(s == 0) depth.at(s) = 0;
    else depth.at(s) = depth.at(p) + 1;
    for(auto next:G[s]){
        if(next != p){
            dfs_d(next, s);
        }
    }
}

vector<ll> star_sz;
void dfs(ll s, ll p){
    for(auto next:G[s]){
        if(next != p){
            star_sz.push_back(G[next].size());
            for(auto leaf:G[next]){
                if(leaf == s) continue;
                for(auto next_leaf :G[leaf]){
                    if(next_leaf != next){
                        dfs(next_leaf, leaf);
                    }
                }
            }
        }
    }
}

int main() {
    ll N;cin>>N;
    G.resize(N);
    depth.resize(N);
    rep(i, N-1){
        ll a, b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs_d(0, -1);
    ll root = -1;
    ll max_depth = -1;
    rep(i, N){
        if(chmax(max_depth, depth.at(i))){
            root = i;
        }
    }
    dfs(root, -1);
    sort(all(star_sz));
    for(auto x:star_sz){
        cout<<x<<" ";
    }
    cout<<"\n";
}