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
    vector<vector<ll>> F(N+1);
    rep(i, N){
        ll f, s;cin>>f>>s;
        F.at(f).push_back(s);
    }
    priority_queue<ll> pq;
    ll ans = -1;
    rep(i, N+1){
        if(F.at(i).empty()) continue;
        sort(all(F.at(i)));
        reverse(all(F.at(i)));
        pq.push(F.at(i).at(0));
        if(F.at(i).size() >= 2){
            ll s = F.at(i).at(0);
            ll t = F.at(i).at(1);
            chmax(ans, s+t/2);
        }
    }
    if(pq.size() >= 2){
        ll s = pq.top();pq.pop();
        ll t = pq.top();pq.pop();
        chmax(ans, s+t);
    }
    out(ans);
}
