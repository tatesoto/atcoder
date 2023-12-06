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

#define ld long double

int main() {
    ld A,B;cin>>A>>B;
    ld M = max(A, B);
    ld m = min(A, B);
    ld a = M/m;
    ld ans = 4;
    ans += 4*a*a;
    ans -= 4*sqrt(3)*a;
    cout<<fixed<<setprecision(32);
    out(sqrt(ans));
}