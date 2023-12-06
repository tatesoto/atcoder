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
    ll ans = 0;
    const ll lim = 1e6;
    for(int i=1;i<=N;i++){
        ll n = N/i;
        if(n <= lim){
            for(int j=1;j<=lim;j++){
                ll m = N/j - N/(j+1);
                ans += m*j;
            }
            break;
        }
        ans += n;
    }
    out(ans);
}