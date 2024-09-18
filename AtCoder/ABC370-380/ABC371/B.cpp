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
    ll N, M;cin>>N>>M;
    vector<ll> A(M);
    vector<char> B(M);
    rep(i, M) cin>>A[i]>>B[i], A[i]--;
    vector<bool> born(N, false);
    vector<bool> ans(M, false);
    rep(i, M) {
        if(B[i] != 'M') continue;
        if(born[A[i]]) continue;
        born[A[i]] = true;
        ans[i] = true;
    }
    rep(i, M) {
        if (ans[i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
