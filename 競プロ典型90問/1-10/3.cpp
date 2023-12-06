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
    Graph G(N+1);
    rep(i,N-1){
        ll a,b;cin>>a>>b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    queue<ll> q;
    vector<ll> dist(N+1,-1);
    q.push(1);
    dist.at(1)=0;
    while(!q.empty()){
        //queから先頭の要素を頂点として採用
        ll pos=q.front();
        q.pop();
        for(auto x:G.at(pos)){
            //posから行ける頂点の内、未確定なもの
            if(dist.at(x)==-1){
                dist.at(x)=dist.at(pos)+1;
                q.push(x);
            }
        }
    }
    ll now=-1;
    ll idx=0;
    for(ll i=1;i<=N;i++){
        if(chmax(now,dist.at(i))){
            idx=i;
        }
    }
    vector<ll> dist2(N+1,-1);
    q.push(idx);
    dist2.at(idx)=0;
    while(!q.empty()){
        //queから先頭の要素を頂点として採用
        ll pos=q.front();
        q.pop();
        for(auto x:G.at(pos)){
            //posから行ける頂点の内、未確定なもの
            if(dist2.at(x)==-1){
                dist2.at(x)=dist2.at(pos)+1;
                q.push(x);
            }
        }
    }
    ll now2=-1;
    for(ll i=1;i<=N;i++){
        chmax(now2,dist2.at(i));
    }
    out(now2+1);
}