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
    Graph G(N+1);
    rep(i,M){
        ll a,b;cin>>a>>b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    for(ll i=1;i<=N;i++){
        cout<<G.at(i).size()<<" ";
        sort(all(G.at(i)));
        rep(j,G.at(i).size()){
            cout<<G.at(i).at(j);
            if(j<G.at(i).size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}