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
const ll mod=1e8;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

int main() {
    ll N;cin>>N;
    vector<ll> A(N);
    ll sum = 0;
    rep(i,N) {
        cin>>A[i];
        sum += A[i];
    }
    sort(all(A));
    ll overmod_cnt = 0;
    //和がmodを超えるペアの数を高速に求める
    for(int i = 0; i < N; i++) {
        ll l = 0, r = N;
        while(r-l > 1) {
            ll mid = (l+r)/2;
            if(A[i]+A[mid] >= mod) r = mid;
            else l = mid;
        }
        if(r <= i) {
            overmod_cnt += N-i-1;
        } else {
            overmod_cnt += N-r;
        }
    }
    ll ans = sum*(N-1) - mod*overmod_cnt;
    out(ans);
}