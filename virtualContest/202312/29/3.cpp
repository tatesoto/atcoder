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
    ll N;cin>>N;
    vector<ll> A(N);
    rep(i, N) cin>>A[i];
    auto label = [&](ll x){
        if(x%4==0) return 2;
        else if(x%2==0) return 1;
        else return 0;
    };
    vector<ll> cnt(3);
    rep(i, N) cnt[label(A[i])]++;
    if(cnt[1] == 0){
        if(cnt[0] <= cnt[2]+1) out("Yes");
        else out("No");
    }else{
        if(cnt[0] <= cnt[2]) out("Yes");
        else out("No");
    }
}
