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
    ll K;cin>>K;
    ll cnt = 0;
    vector<ll> p_cnt(N+1, 0);
    for(int i=2;i<=N;i++){
        if(p_cnt.at(i) == 0){
            for(int j=i;j<=N;j+=i){
                p_cnt.at(j)++;
            }
        }
    }
    for(int i=2;i<=N;i++){
        if(p_cnt.at(i) >= K) cnt++;
    }
    out(cnt);
}