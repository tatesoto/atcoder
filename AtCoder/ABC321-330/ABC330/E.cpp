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
    ll N, Q;cin>>N>>Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> I(Q), X(Q);
    rep(i,Q) cin>>I[i]>>X[i], I[i]--;
    map<ll, ll> mp;
    set<ll> st;
    rep(i, N) mp[A[i]]++;
    rep(i, N+1) if(mp[i] == 0) st.insert(i);

    auto mex = [&]{
        return *st.begin();
    };

    auto query = [&](ll i, ll x){
        mp[A[i]]--;
        if(mp[A[i]] == 0) st.insert(A[i]);
        A[i] = x;
        mp[A[i]]++;
        if(mp[A[i]] == 1) st.erase(A[i]);
        out(mex());
    };

    rep(i, Q) query(I[i], X[i]);

}