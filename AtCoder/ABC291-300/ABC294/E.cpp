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
    ll L,N1,N2;cin>>L>>N1>>N2;
    ll now_l1 = 0, now_l2 = 0;
    ll now_l = 0;
    set<ll> l12, l1, l2;
    queue<ll> v1, v2;
    rep(i, N1){
        ll v, l;cin>>v>>l;
        v1.push(v);
        now_l1 += l;
        l1.insert(now_l1);
        l12.insert(now_l1);
    }
    rep(i, N2){
        ll v, l;cin>>v>>l;
        v2.push(v);
        now_l2 += l;
        l2.insert(now_l2);
        l12.insert(now_l2);
    }
    ll ans = 0;
    for(auto l:l12){
        ll w1 = v1.front();
        ll w2 = v2.front();
        if(l1.count(l)) v1.pop();
        if(l2.count(l)) v2.pop();
        if(w1 == w2) ans += l - now_l;
        now_l = l;
    }
    out(ans);
}