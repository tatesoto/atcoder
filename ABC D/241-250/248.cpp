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
    vector<ll> a(N+1);
    rep(i,N) cin>>a.at(i+1);
    vector<vector<ll>> count(N+1);
    rep(i,N){
        count.at(a.at(i+1)).push_back(i+1);
    }
    ll Q;cin>>Q;
    rep(i,Q){
        ll l,r,x;cin>>l>>r>>x;
        ll left=-distance(lower_bound(all(count.at(x)),l),count.at(x).begin());
        ll right=-distance(upper_bound(all(count.at(x)),r),count.at(x).begin());
        out(right-left);
    }
}