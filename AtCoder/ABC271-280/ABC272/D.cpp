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

typedef tuple<ll,ll,ll> P;
vector<ll> dx;
vector<ll> dy;
ll N;

vector<vector<ll>> dist;
//startからダイクストラ法
//計算量O(NlogM);
void dijkstra(ll s,ll t){
    //{距離,行先}を保存
    priority_queue<P,vector<P>,greater<P>> pq;
    dist.at(1).at(1)=0;
    pq.push(P(0,s,t));

    while(!pq.empty()){
        P  p=pq.top();
        pq.pop();
        ll fx=get<1>(p);
        ll fy=get<2>(p);
        for(ll dir=0;dir<dx.size();dir++){
            ll tx=fx+dx.at(dir);
            ll ty=fy+dy.at(dir);
            if(tx<1||ty<1||tx>N||ty>N) continue;
            //小さかったら更新
            if(dist.at(tx).at(ty)>dist.at(fx).at(fy)+1){
                dist.at(tx).at(ty)=dist.at(fx).at(fy)+1;
                pq.push(P(dist.at(tx).at(ty),tx,ty));
            }
        }
    }
}

int main() {
    cin>>N;
    ll M;cin>>M;
    for(ll i=0;i*i<=M;i++){
        for(ll j=i;;j++){
            if(i*i+j*j>M){
                break;
            }
            if(i*i+j*j==M){
                dx.push_back(i);dy.push_back(j);
                dx.push_back(-i);dy.push_back(j);
                dx.push_back(i);dy.push_back(-j);
                dx.push_back(-i);dy.push_back(-j);
                dx.push_back(j);dy.push_back(i);
                dx.push_back(-j);dy.push_back(i);
                dx.push_back(j);dy.push_back(-i);
                dx.push_back(-j);dy.push_back(-i);
                break;
            }
        }
    }

    dist.resize(N+1,vector<ll>(N+1,INF));
    dijkstra(1,1);
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            if(dist.at(i).at(j)==INF){
                cout<<-1;
            }
            else{
                cout<<dist.at(i).at(j);
            }
            if(j!=N){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}