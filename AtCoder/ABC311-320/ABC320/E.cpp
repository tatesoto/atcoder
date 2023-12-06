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
    ll N, M;cin>>N>>M;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i, N) pq.push(i);
    priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll,ll>>>> time;
    rep(i, M){
        ll t, w, s;cin>>t>>w>>s;
        time.push({t, {w, s}});
    }
    vector<ll> ans(N, 0);
    while(!time.empty()){
        auto [t, p] = time.top();time.pop();
        auto [w, s] = p;
        if(w == 0){
            pq.push(s);
        }
        else{
            if(!pq.empty()){
                auto i = pq.top();pq.pop();
                ans[i] += w;
                time.push({t+s, {0, i}});
            }
        }
    }
    rep(i, N) out(ans[i]);
}
