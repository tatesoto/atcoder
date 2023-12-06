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
    for(ll i=2;i<=N;i++){
        ll a;cin>>a;
        G.at(a).push_back(i);
    }
    vector<ll> dp(N+1,0);
    for(ll i=N;i>=1;i--){
        for(auto x:G.at(i)){
            dp.at(i)+=dp.at(x);
            dp.at(i)++;
        }
    }
    for(ll i=1;i<=N;i++){
        cout<<dp.at(i);
        if(i<N){
            cout<<" ";
        }
    }
    cout<<endl;
}