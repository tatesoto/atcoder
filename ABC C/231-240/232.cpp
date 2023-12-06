#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using Graph = vector<vector<ll>>;

int main() {
    ll N,M;
    cin>>N>>M;
    //隣接行列(G[i][j]：iからjに向かう辺があるなら1)
    Graph G(N,vector<ll>(N,0));
    rep(i,M){
        //a,bは辺の両端
        ll a,b;
        cin>>a>>b;
        G[a-1][b-1]=1;
        //無向グラフなら以下を追加
        G[b-1][a-1]=1;
    }
    //隣接行列(G[i][j]：iからjに向かう辺があるなら1)
    Graph H(N,vector<ll>(N,0));
    rep(i,M){
        //a,bは辺の両端
        ll a,b;
        cin>>a>>b;
        H[a-1][b-1]=1;
        //無向グラフなら以下を追加
        H[b-1][a-1]=1;
    }
    vector<ll> p(N);
    iota(all(p),0);
    do{
        bool judge=true;
        rep(i,N){
            rep(j,N){
                if(G.at(i).at(j)!=H.at(p.at(i)).at(p.at(j))){
                    judge=false;
                }
            }
        }
        if(judge){
            out("Yes");
            return 0;
        }
    }
    while(next_permutation(all(p)));
    out("No");
}