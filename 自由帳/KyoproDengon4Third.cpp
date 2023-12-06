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
    ll T;cin>>T;
    vector<ll> ans;
    rep(i, T){
        ll N;cin>>N;
        vector<ll> P(N);
        rep(j, N){
            ll x;cin>>x;x--;
            P.at(x) = j;
        }
        ll cnt = 0;
        ll tmp = -1;
        rep(j, N){
            if(chmax(tmp, P.at(j))) cnt++;
        }
        ans.push_back(cnt);
    }
    rep(i, T){
        out(ans.at(i));
    }
}
