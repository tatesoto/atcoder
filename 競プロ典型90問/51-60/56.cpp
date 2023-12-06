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
    ll N, S;cin>>N>>S;
    vector<pair<ll,ll>> a(N+1);
    rep(i, N) cin>>a.at(i+1).first>>a.at(i+1).second;
    vector<vector<bool>> dp(N+1, vector<bool>(200000, false));
    dp.at(0).at(0) = true;
    for(int i=1;i<=N;i++){
        rep(j, S){
            if(dp.at(i-1).at(j)){
                dp.at(i).at(j+a.at(i).first) = true;
                dp.at(i).at(j+a.at(i).second) = true;
            }
        }
    }
    string ans = "";
    if(dp.at(N).at(S)){
        ll now = S;
        for(int i=N;i>0;i--){
            if(now-a.at(i).first >= 0 && dp.at(i-1).at(now-a.at(i).first)){
                now -= a.at(i).first;
                ans.push_back('A');
            }
            else{
                now -= a.at(i).second;
                ans.push_back('B');
            }
        }
        reverse(all(ans));
        out(ans);
    }
    else{
        out("Impossible");
    }
}