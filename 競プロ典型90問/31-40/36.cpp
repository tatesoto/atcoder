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
    ll Q;cin>>Q;
    vector<ll> x(N), y(N);
    ll mx = INF, my = INF;
    ll Mx = -INF, My = -INF;
    rep(i, N){
        ll a, b;cin>>a>>b;
        x.at(i) = a-b;
        y.at(i) = a+b;
        chmin(mx, x.at(i));
        chmin(my, y.at(i));
        chmax(Mx, x.at(i));
        chmax(My, y.at(i));
    }
    rep(i, Q){
        ll q;cin>>q;q--;
        ll ans = max(x.at(q) - mx, Mx - x.at(q));
        chmax(ans, max(y.at(q) - my, My - y.at(q)));
        out(ans);
    }
}