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

//約数の個数
ll prime_factor(ll N){
    map<ll,ll> ans;
    for(ll i=2;i*i<=N;i++){
        while(N%i==0){
            ans[i]++;
            N/=i;
        }
    }
    if(N!=1){
        ans[N]=1;
    }
    ll res = 0;
    for(auto x:ans){
        res += x.second;
    }
    return res;
}

int main() {
    ll N;cin>>N;
    vector<ll> A(N);
    rep(i, N) cin>>A[i];
    vector<ll> B(N);
    rep(i, N) {
        B[i] = prime_factor(A[i]);
    }
    ll nim = 0;
    rep(i, N) {
        nim ^= B[i];
    }
    if (nim == 0) {
        out("Bruno");
    }
    else {
        out("Anna");
    }

}
