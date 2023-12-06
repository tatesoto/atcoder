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
    ll N;cin>>N;
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    vector<string> s(N);
    rep(i,N) cin>>s.at(i);
    Graph G(N);
    rep(i,N){
        rep(j,N){
            if(s.at(i).at(j)=='Y'){
                G.at(i).push_back(j);
            }
        }
    }
    vector<vector<ll>> Dist(N, vector<ll>(N,INF));
    vector<vector<ll>> Value(N,vector<ll>(N,-1));
    rep(i,N){
        queue<ll> q;
        vector<ll> &dist=Dist.at(i);
        vector<ll> &value=Value.at(i);
        dist.at(i) = 0;
        value.at(i) = a.at(i);
        q.push(i);
        while(!q.empty()){
            ll pos = q.front();
            q.pop();
            for(auto x:G.at(pos)){
                if(dist.at(x)<dist.at(pos)+1) continue;
                dist.at(x) = dist.at(pos) + 1;
                chmax(value.at(x),value.at(pos)+a.at(x));
                q.push(x);
            }
        }
    }
    ll Q;cin>>Q;
    vector<pair<ll,ll>> uv(Q);
    rep(i,Q) cin>>uv.at(i).first>>uv.at(i).second;
    rep(i,Q){
        ll u=uv.at(i).first;
        ll v=uv.at(i).second;
        u--;v--;
        if(Dist.at(u).at(v) == INF){
            out("Impossible");
        }
        else out(Dist.at(u).at(v)<<" "<<Value.at(u).at(v));
    }
}