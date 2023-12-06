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

Graph G;
vector<ll> color;

//startを含む連結成分の二部グラフ判定
bool Is_Biparate_Graph(const Graph &G, ll s, ll cur = 0){
    color.at(s) = cur;
    for(auto to: G.at(s)){
        if(color.at(to) != -1){
            if(color.at(to) == cur) return false;
            continue;
        }
        if(!Is_Biparate_Graph(G, to, 1 - cur)) return false;
    }
    return true;
}

int main() {
    
}