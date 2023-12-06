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
    ll N;cin>>N;
    ll M;cin>>M;
    vector<ll> A(N, 0), B(M, 0);
    rep(i, N) cin>>A.at(i);
    rep(i, M) cin>>B.at(i);
    ll ans = 0;
    rep(i, M){
        ans += A.at(B.at(i) - 1);
    }
    out(ans);
}