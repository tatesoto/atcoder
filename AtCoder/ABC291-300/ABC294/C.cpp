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
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N,M;cin>>N>>M;
    vector<pair<ll,ll>> C(N+M);
    rep(i, N+M){
        ll a;cin>>a;
        C.at(i) = {a, i};
    }
    sort(all(C));
    vector<ll> AB(N+M);
    rep(i, N+M){
        AB.at(C.at(i).second) = i+1;
    }
    rep(i, N+M){
        cout<<AB.at(i);
        if(i == N-1 || i == N + M - 1){
            cout<<endl;
        }
        else{
            cout<<" ";
        }
    }
}