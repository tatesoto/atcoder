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
    ll N;cin>>N;
    vector<ll> A(N);
    rep(i, N) cin>>A.at(i);
    ll Q;cin>>Q;
    vector<ll> l(Q), r(Q);
    rep(i, Q) cin>>l.at(i)>>r.at(i);
    vector<ll> sum(N, 0);
    for(int i = 1;i < N;i++) sum.at(i) = sum.at(i-1) + (1 - i%2)*(A.at(i) - A.at(i-1));
    rep(q, Q){
        ll ans = 0;
        auto l_it = lower_bound(all(A), l.at(q));
        ll l_id = distance(A.begin(), l_it);
        if(l_id%2 == 0){
            ans += A.at(l_id) - l.at(q);
        }
        auto r_it = lower_bound(all(A), r.at(q));
        ll r_id = distance(A.begin(), r_it);
        if(r_id%2 == 0){
            ans -= A.at(r_id) - r.at(q);
        }
        ans += sum.at(r_id) - sum.at(l_id);
        out(ans);
    }
}