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
    vector<ll> a(N);
    rep(i, N) cin>>a.at(i);
    string S;cin>>S;
    map<char, ll> mp;
    string MEX = "MEX";
    rep(i, 3) mp[MEX.at(i)] = i+1;
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(4, vector<ll>(8, 0)));
    dp.at(0).at(0).at(0) = 1;
    for(int i = 1; i <= N; i++){
        rep(j, 4){
            ll x = mp[S.at(i-1)];
            rep(k, 8){
                dp.at(i).at(j).at(k) += dp.at(i-1).at(j).at(k);
                if(j == x){
                    dp.at(i).at(j).at((k|(1LL<<a.at(i-1)))) += dp.at(i-1).at(j-1).at(k);
                }
            }
        }
    }
    ll ans = 0;
    ans += 1LL*dp.at(N).at(3).at(1);
    ans += 2LL*dp.at(N).at(3).at(3);
    ans += 1LL*dp.at(N).at(3).at(5);
    ans += 3LL*dp.at(N).at(3).at(7);
    out(ans);
}