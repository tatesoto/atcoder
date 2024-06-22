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
    ll n;cin>>n;
    vector<ll> fib(n+1);
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++) {
        fib[i]=fib[i-1]+fib[i-2];
    }
    out(fib[n]);
    auto to_hex=[](ll x) {
        string res;
        while(x) {
            ll d=x%16;
            if(d<10) res+=to_string(d);
            else res+=char('A'+d-10);
            x/=16;
        }
        reverse(all(res));
        return res;
    };
    out("hex: " << to_hex(fib[n]));
}
