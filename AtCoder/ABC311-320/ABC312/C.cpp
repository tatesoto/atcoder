#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N, M;cin>>N>>M;
    vector<ll> A(N), B(M);
    rep(i, N) cin>>A.at(i);
    rep(i, M) cin>>B.at(i);
    sort(all(A));
    sort(all(B));
    ll l = 0;
    ll r = 1e10;
    while(r - l > 1){
        ll mid = (l+r)/2;
        auto iter1 = lower_bound(all(B), mid);
        ll n1 = B.end() - iter1;
        auto iter2 = upper_bound(all(A), mid);
        ll n2 = iter2 - A.begin();
        if(n2 < n1){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    out(r);
}