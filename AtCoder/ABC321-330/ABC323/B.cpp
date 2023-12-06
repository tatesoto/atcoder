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

int main() {
    ll N;cin>>N;
    Grid G(N);
    rep(i, N) cin>>G[i];
    vector<ll> wins(N, 0);
    rep(i, N){
        rep(j, N){
            if(G[i][j] == 'o') wins[i]++;
        }
    }
    priority_queue<ll> pq;
    rep(i, N){
        ll n = wins[i]*1000 + 100 - i;
        pq.push(n);
    }
    while(!pq.empty()){
        auto n = pq.top();pq.pop();
        auto x = 100 - (n%1000) + 1; 
        out(x);
    }
    
}