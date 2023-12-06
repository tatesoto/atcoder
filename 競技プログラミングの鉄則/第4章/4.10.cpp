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
    ll H,W;cin>>H>>W;
    vector<vector<char>> G(H+1,vector<char>(W+1));
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cin>>G.at(i).at(j);
        }
    }
    Graph dp(H+1,vector<ll>(W+1,0));
    dp.at(1).at(1)=1;
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            if(i*j==1) continue;
            if(G.at(i).at(j)=='#') dp.at(i).at(j)=0;
            else{
                dp.at(i).at(j)=dp.at(i-1).at(j)+dp.at(i).at(j-1);
            }
        }
    }
    out(dp.at(H).at(W));
}