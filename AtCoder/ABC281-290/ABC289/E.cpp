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

int main() {
    ll T;cin>>T;
    rep(i, T){
        ll N,M;cin>>N>>M;
        vector<ll> c(N);
        rep(i, N) cin>>c.at(i);
        //Gは同色、Hは異色
        Graph G(N),H(N);
        rep(i, M){
            ll u,v;cin>>u>>v;
            u--;v--;
            if(c.at(u) == c.at(v)){
                G[u].push_back(v);
                G[v].push_back(u);
            }
            else{
                H[u].push_back(v);
                H[v].push_back(u);
            }
        }
        if(c.at(0) == c.at(N-1)){
            out(-1);
            continue;
        }
        Graph dist(N, vector<ll>(N, -1));
        dist.at(0).at(N-1) = 0;
        queue<ll> q1, q2;
        q1.push(0);
        q2.push(N-1);
        while(!q1.empty()){
            ll pos1 = q1.front();
            ll pos2 = q2.front();
            q1.pop();
            q2.pop();
            for(auto x:G[pos1]){
                for(auto y:G[pos2]){
                    if(dist.at(x).at(y) == -1){
                        dist.at(x).at(y) = dist.at(pos1).at(pos2) + 1;
                        q1.push(x);
                        q2.push(y);
                    }
                }
            }
            for(auto x:H[pos1]){
                for(auto y:H[pos2]){
                    if(dist.at(x).at(y) == -1){
                        dist.at(x).at(y) = dist.at(pos1).at(pos2) + 1;
                        q1.push(x);
                        q2.push(y);
                    }
                }
            }
        }
        out(dist.at(N-1).at(0));
    }
}