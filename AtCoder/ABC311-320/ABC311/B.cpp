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
    ll N, D;cin>>N>>D;
    vector<string> S(N);
    rep(i, N) cin>>S.at(i);
    ll ans = 0;
    ll cnt = 0;
    rep(i, D){
        bool judge = true;
        rep(j, N){
            if(S.at(j).at(i) == 'x') judge = false;
        }
        if(judge){
            cnt++;
            if(i == D-1){
                chmax(ans, cnt);
            }
        }
        else{
            chmax(ans, cnt);
            cnt = 0;
        }
    }
    out(ans);
}