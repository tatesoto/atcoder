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
using Graph = vector<set<ll>>;


Graph G, H;

int main() {
    ll N,M;cin>>N>>M;
    G.resize(N);
    H.resize(N);
    rep(i, M){
        ll a,b;cin>>a>>b;
        a--;
        b--;
        G[a].insert(b);
        H[b].insert(a);
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i, N){
        if(H[i].size() == 0){
            pq.push(i);
        }
    }
    vector<ll> P;
    while(!pq.empty()){
        ll pos = pq.top();
        pq.pop();
        P.push_back(pos);
        for(auto x:G[pos]){
            H[x].erase(pos);
            if(H[x].size() == 0){
                pq.push(x);
            }
        }
    }
    if(P.size() == N){
        rep(i,N){
            cout<<P.at(i) + 1;
            if(i == N-1){
                cout<<endl;
            }
            else{
                cout<<" ";
            }
        }
    }
    else{
        out(-1);
    }
}