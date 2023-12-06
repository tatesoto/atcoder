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
    ll N,X,Y;cin>>N>>X>>Y;
    vector<ll> a(N+1, -1);
    rep(i, N) cin>>a.at(i);
    ll x_range = 0, y_range = 0, xy_range = 0;
    ll ans = N*(N+1)/2;
    rep(i, N+1){
        bool change = false;
        if(a.at(i) == X || i == N){
            ans -= x_range*(x_range+1)/2;
            x_range = 0;
            change = true;
            out(ans);
        }
        else{
            x_range++;
        }
        if(a.at(i) == Y || i == N){
            ans -= y_range*(y_range+1)/2;
            y_range = 0;
            change = true;
            out(ans);
        }
        else{
            y_range++;
        }
        if(change || i == N){
            ans += xy_range*(xy_range+1)/2;
            xy_range = 0;
            out(ans);
        }
        else{
            xy_range++;
        }
    }
    out(ans);
}