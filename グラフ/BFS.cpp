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
vector<ll> dist;

//startからBFS
void BFS(ll s){
    queue<ll> q;
    q.push(s);
    dist.at(s) = 0;
    while(!q.empty()){
        ll pos = q.front();
        q.pop();
        for(auto to:G.at(pos)){
            if(dist.at(to) == -1){
                dist.at(to) = dist.at(pos) + 1;
                q.push(to);
            }
        }
    }
}

int main(){
    
}