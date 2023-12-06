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
    vector<ll> C(10);
    rep(i, 9) cin>>C.at(i+1);
    ll min_C = INF;
    rep(i, 9) chmin(min_C, C.at(i+1));
    ll digit_n = N/min_C;
    string S;
    ll cost = N;
    rep(i, digit_n){
        ll next = -1;
        ll rest_len = digit_n - i - 1;
        for(ll j=1;j<=9;j++){
            ll rest_cost = cost - C.at(j);
            if(0 <= rest_cost && rest_len <= rest_cost/min_C){
                next = j;
            }
        }
        cost -= C.at(next);
        S += '0' + next;
    }
    out(S);
}