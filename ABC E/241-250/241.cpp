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
    ll N, K;cin>>N>>K;
    vector<ll> a(N);
    rep(i, N) cin>>a.at(i);
    vector<ll> cnt(N, -1);
    ll candy = 0;
    ll pre = -1;
    ll roop = -1;
    queue<ll> q;
    rep(i, K){
        ll pos = candy%N;
        if(cnt.at(pos) != -1){
            roop = i - cnt.at(pos);
            pre = cnt.at(pos);
            rep(j, pre){
                q.pop();
            }
            break;
        }
        cnt.at(pos) = i;
        q.push(pos);
        candy += a.at(pos);
    }
    candy = 0;
    if(pre == -1){
        rep(i, K){
            ll pos = candy%N;
            candy += a.at(pos);
        }
        out(candy);
        return 0;
    }
    else{
        rep(i, pre){
            ll pos = candy%N;
            candy += a.at(pos);
        }
        ll k = K - pre;
        ll roop_n = k/roop;
        ll m = k%roop;
        ll roop_candy = 0;
        rep(i, roop){
            ll x = q.front();q.pop();q.push(x);
            roop_candy += a.at(x);
        }
        candy += roop_candy*roop_n;
        rep(i, m){
            ll x = q.front();q.pop();
            candy += a.at(x);
        }
        out(candy);
    }
}