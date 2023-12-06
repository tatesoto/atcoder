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
    ll X;cin>>X;
    vector<ll> a(N);
    set<ll> st;
    rep(i, N) cin>>a.at(i);
    rep(i, N) st.insert(a.at(i));
    rep(i, N){
        if(st.count(a.at(i) + X)){
            out("Yes");
            return 0;
        }
    }
    out("No");
}