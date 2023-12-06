#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using Graph = vector<vector<int>>;


int main() {
    ll N,M;
    cin>>N>>M;
    Graph G(N);
    for (ll i = 0; i < M; ++i) {
        //a,bは辺の両端
        ll a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        //無向グラフなら以下を追加
        G[b-1].push_back(a-1);
    }
    ll ans=0;
    for(int bit=0;bit<(1<<N);bit++){
        vector<ll> data;
        set<ll> g;
        bool j=true;
        for(int i=0;i<N;i++){
            if(bit & (1<<i)){
                data.push_back(i);
                if(j){
                    for(auto x:G.at(i)){
                        g.insert(x);
                    }
                    g.insert(i);
                    j=false;
                }
            }
        }
        bool judge=true;
        for(ll i=0;i<data.size();i++){
            if(!g.count(data.at(i))){
                judge=false;
            }
        }
        if(judge){
            ll n=data.size();
            ans=max(ans,n);
        }
        data.clear();
        g.clear();
    }
    out(ans);   
}