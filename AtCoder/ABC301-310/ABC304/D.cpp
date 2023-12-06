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
    ll W, H;cin>>W>>H;
    ll N;cin>>N;
    vector<pair<ll,ll>> berry(N);
    rep(i, N){
        ll p, q;cin>>p>>q;
        berry.at(i) = {p, q};
    }
    ll A;cin>>A;
    vector<ll> a(A);
    rep(i, A){
        cin>>a.at(i);
    }
    ll B;cin>>B;
    vector<ll> b(B);
    rep(i, B){
        cin>>b.at(i);
    }
    map<pair<ll,ll>,ll> mp;
    rep(i, N){
        ll x = berry.at(i).first;
        ll y = berry.at(i).second;
        ll xd = distance(a.begin(), lower_bound(all(a), x));
        ll yd = distance(b.begin(), lower_bound(all(b), y));
        mp[{xd, yd}]++; 
    }
    ll ans_min = INF;
    ll ans_max = -1;
    for(auto p:mp){
        chmin(ans_min, p.second);
        chmax(ans_max, p.second);
    }
    if(mp.size() < (A+1) * (B+1)) ans_min = 0;
    cout<<ans_min<<" "<<ans_max<<"\n";
}