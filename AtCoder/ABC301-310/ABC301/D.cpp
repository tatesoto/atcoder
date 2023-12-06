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

void solve(string S, ll N){
    set<ll> change;
    ll now = 0;
    rep(i, S.size()){
        ll n = S.at(i) - '0';
        if(S.at(i) == '?'){
            change.insert(S.size()-i-1);
            n = 0;
        }
        now *= 2;
        now += n;
    }
    if(N < now){
        out("-1");
        return;
    }
    for(int i = S.size()-1;i>=0;i--){
        if(!change.count(i)) continue;
        ll res = now;
        res |= (1LL<<i);
        if(res <= N) now = res;
    }
    out(now);
}

int main() {
    string S;cin>>S;
    ll N;cin>>N;
    solve(S, N);
}