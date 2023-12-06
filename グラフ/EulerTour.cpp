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
using Network = vector<vector<pair<ll,ll>>>;


//uを根とする部分木は[lb[u],rb[u])で表せる
 
//行きがけ、通りがけ、帰りがけのすべてを記録
Graph G;
//ord:オイラーツアー順序, id[x]:xを最初に訪れたのがオイラーツアー順序の何番目か
vector<ll> ord, lb, rb, id;

 
void dfs(int u,int p)
{
    id[u] = ord.size();
    lb[u] = (int)ord.size();
    ord.push_back(u);
    for(int v : G[u]){
        if(v != p){
            dfs(v,u);
            ord.push_back(u);
        }
    }
    rb[u] = (int)ord.size() - 1;
}

int main() {
    
}