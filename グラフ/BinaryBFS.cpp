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

Network G;
vector<ll> dist;

//startから01BFS
void BinaryBFS(ll s){
    deque<ll> dq;
    dq.push_back(s);
    dist.at(s) = 0;
    while(!dq.empty()){
        ll pos = dq.front();
        dq.pop_front();
        for(auto to_cost:G.at(pos)){
            ll to = to_cost.first;
            ll cost = to_cost.second;
            if(dist.at(to) == -1){
                dist.at(to) = dist.at(pos) + cost;
                if(cost){
                    dq.push_back(to);
                }
                else{
                    dq.push_front(to);
                }
            }
        }
    }
}

int main() {
    
}