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
    ll N;cin>>N;
    vector<ll> a(N);
    ll sum = 0;
    rep(i, N){
        cin>>a.at(i);
        sum += a.at(i);
    }
    ll ave = sum/N;
    ll x = (ave+1)*N - sum;
    vector<ll> b(N);
    rep(i, N){
        if(i < x) b.at(i) = ave;
        else b.at(i) = ave + 1;
    }
    sort(all(a));
    ll cnt = 0;
    rep(i, N){
        cnt += abs(a.at(i) - b.at(i));
    }
    out(cnt/2);
}
