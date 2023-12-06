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
    ll N;cin>>N;
    vector<ll> a(N);
    set<ll> st;
    ll ans = 0;
    rep(i, N){
        cin>>a.at(i);
        a.at(i)--;
    }
    for(ll i=N-1;i>=0;i--){
        st.insert(a.at(i));
        ll post_cnt = distance(st.begin(), st.find(a.at(i)));
        ll move = i + post_cnt - a.at(i);
        ans += move/2 + move%2;
    }
    out(ans);
}