#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N, K;cin>>N>>K;
    map<ll, ll> mp;
    rep(i, N){
        ll a;cin>>a;mp[-a]++;
    }
    vector<pair<ll,ll>> A;
    for(auto p:mp){
        ll a = -p.first;
        ll n = p.second;
        A.push_back({a, n});
    }
    A.push_back({0, -1});
    ll ans = 0;
    ll n = 0;
    rep(i, A.size()-1){
        ll a = A.at(i).first;
        ll b = A.at(i+1).first;
        n += A.at(i).second;
        if(K == 0){
            out(ans);
            return 0;
        }
        if((a-b)*n <= K){
            ans += n*(a-b)*(a+b+1)/2;
            K -= (a-b)*n;
        }
        else{
            ll q = K/n;
            ll r = K%n;
            ans += n*q*(2*a-q+1)/2;
            ans += r*(a-q);
            K = 0;
        }
    }
    out(ans);
}