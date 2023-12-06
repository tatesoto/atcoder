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
    ll N,M;cin>>N>>M;
    Graph G(N), H(N);
    rep(i, M){
        ll a;cin>>a;
        a--;
        G[a+1].push_back(a);
        H[a].push_back(a+1);
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i, N){
        if(H[i].size() == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        ll pos = pq.top();
        pq.pop();
        for(auto x:G[pos]){
            pq.push(x);
        }
        pos++;
        cout<<pos;
        if(!pq.empty()){
            cout<<" ";
        }
    }
    cout<<endl;
}