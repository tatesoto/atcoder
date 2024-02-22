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
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

int main() {
    ll N, K;cin>>N>>K;
    vector<ll> A(N);
    rep(i, N) cin>>A[i];
    auto judge = [&](ll x){
        ll cnt = 0;
        rep(i, N){
            cnt += (A[i] + x - 1) / x - 1;
        }
        return cnt <= K;
    };
    ll l = 0, r = INF;
    while(r - l > 1){
        ll mid = (l + r) / 2;
        if(judge(mid)) r = mid;
        else l = mid;
    }
    out(r);
}
