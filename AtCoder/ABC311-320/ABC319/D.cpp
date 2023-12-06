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
    vector<ll> L(N);
    ll lmax = -1;
    rep(i, N){
        cin>>L[i];
        chmax(lmax, L[i]);
    }
    ll l = lmax-1;
    ll r = 1e15;
    auto isok = [&](ll k){
        ll now = 0;
        ll cnt = 1;
        rep(i, N){
            if(now + L[i] > k){
                now = L[i] + 1;
                cnt++;
            }
            else{
                now += L[i] + 1;
            }
        }
        if(cnt <= M) return true;
        else return false;
    };
    while(r-l>1){
        ll mid = (l + r)/2;
        if(isok(mid)) r = mid;
        else l = mid;
    }
    out(r);
}
