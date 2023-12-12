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

ll N, K;
vector<ll> vec;
bool check(ll x){
    ll total = 0;
    rep(i, N){
        total += x / vec[i];
    }
    return total >= K;
}


int main() {
    cin>>N>>K;
    vec.resize(N);
    rep(i, N) cin>>vec[i];

    ll l = 0;
    ll r = 1e9;
    while(r-l > 1){
        ll mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    out(r);
}