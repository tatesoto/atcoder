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

int main() {
    ll N, M;cin>>N>>M;
    vector<set<ll>> S(N);
    vector<set<ll>> Sid(M);
    rep(i, N){
        ll a;cin>>a;
        rep(j, a){
            ll x;cin>>x;
            x--;
            S.at(i).insert(x);
            Sid.at(x).insert(i);
        }
    }
    vector<ll> dist(M, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    set<ll> seen_S;
    for(auto id:Sid.at(0)){
        seen_S.insert(id);
        for(auto nv:S.at(id)){
            if(chmin(dist.at(nv), 0LL)){
                pq.push({0, nv});
            }
        }
    }
    while(!pq.empty()){
        auto p = pq.top();pq.pop();
        ll d = p.first;
        ll pos = p.second;
        if(dist.at(pos) < d) continue;
        for(auto id:Sid.at(pos)){
            if(seen_S.count(id)) continue;
            seen_S.insert(id);
            for(auto nv:S.at(id)){
                if(chmin(dist.at(nv), dist.at(pos) + 1LL)){
                    pq.push({dist.at(nv), nv});
                }
            }
        }
    }
    if(dist.at(M-1) == INF) out(-1);
    else out(dist.at(M-1));
}