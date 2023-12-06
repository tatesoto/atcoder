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
    ll N,M;cin>>N>>M;
    set<ll> s;
    set<ll> mcnt;
    queue<ll> q;
    rep(i,M){
        mcnt.insert(i);
    }
    vector<vector<ll>> G(N);
    vector<queue<ll>> cyl(M);
    rep(i,M){
        ll k;cin>>k;
        rep(j,k){
            ll a;cin>>a;
            a--;
            cyl.at(i).push(a);
        }
        G.at(cyl.at(i).front()).push_back(i);
    }
    rep(i,N){
        if(G.at(i).size()==2){
            q.push(i);
        }
    }
    while(!q.empty()){
        ll x=q.front();q.pop();
        for(auto p:G.at(x)){
            cyl.at(p).pop();
            if(!cyl.at(p).empty()){
                ll y=cyl.at(p).front();
                G.at(y).push_back(p);
                if(G.at(y).size()==2){
                    q.push(y);
                }
            }
        }
    }
    rep(i,M){
        if(!cyl.at(i).empty()){
            out("No");
            return 0;
        }
    }
    out("Yes");
}