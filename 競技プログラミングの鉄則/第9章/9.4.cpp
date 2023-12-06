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

int main() {
    ll N,M;
    cin>>N>>M;
    vector<vector<pair<ll,ll>>> G(N+1);
    for(ll i=1;i<=M;i++){
        ll a,b,c;cin>>a>>b>>c;
        G.at(a).push_back(make_pair(b,c));
        G.at(b).push_back(make_pair(a,c));
    }

    vector<ll> dist(N+1,INF);
    vector<bool> check(N+1,false);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    dist.at(1)=0;
    pq.push(make_pair(dist.at(1),1));

    while(!pq.empty()){
        ll pos=pq.top().second;
        pq.pop();
        if(check.at(pos)) continue;
        check.at(pos)=true;
        for(auto p:G.at(pos)){
            ll next=p.first;
            ll cost=p.second;
            chmin(dist.at(next),dist.at(pos)+cost);
            pq.push(make_pair(dist.at(next),next));
        }
    }
    for(ll i=1;i<=N;i++){
        if(dist.at(i)==INF) out(-1);
        else out(dist.at(i));
    }
}