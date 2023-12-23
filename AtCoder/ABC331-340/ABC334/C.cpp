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
    set<ll> A;
    rep(i, K){
        ll a;cin>>a;
        A.insert(a);
    }
    vector<ll> B;
    rep(i, N){
        B.push_back(i+1);
        if(!A.count(i+1)) B.push_back(i+1);
    }
    sort(all(B));
    vector<ll> sum(B.size()+1, 0);
    rep(i, B.size()){
        if(i % 2 == 0) sum[i+1] = sum[i] - B[i];
        else sum[i+1] = sum[i] + B[i];
    }
    ll ans = INF;
    if(B.size()%2 == 0){
        out(sum[B.size()]);
    }
    else{
        rep(i, B.size()){
            ll after = sum[B.size()] - sum[i+1];
            ll before = sum[i];
            chmin(ans, before - after);
        }
        out(ans);
    }
}