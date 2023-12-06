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
    vector<ll> a(N);
    rep(i, N) cin>>a.at(i);
    ll M;cin>>M;
    set<ll> b;
    rep(i, M){
        ll x;cin>>x;
        b.insert(x);
    }
    ll X;cin>>X;
    vector<bool> dp(X+1, false);
    dp.at(0) = true;
    for(ll i=0;i<X;i++){
        if(!dp.at(i)) continue;
        if(b.count(i)){
            dp.at(i) = false;
            continue;
        }
        rep(j,N){
            if(i + a.at(j) <= X){
                dp.at(i + a.at(j)) = dp.at(i);
            }
        }
    }
    if(dp.at(X)){
        out("Yes");
    }
    else{
        out("No");
    }
}