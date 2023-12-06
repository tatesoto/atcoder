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

vector<ll> a;
set<ll> s;
ll N;

// index が条件を満たすかどうか
bool isOK(ll key,ll m) {
    for(ll i=1;i<=N;i++){
        if (s.count((key-m*i))*1000000+i) return true;
    }
    return false;
}


// 汎用的な二分探索のテンプレ
ll binary_search(ll m) {
    ll ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = 1000000; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid,m)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    cin>>N;
    ll M;cin>>M;
    a.resize(N);
    rep(i,N){
        ll x;cin>>x;
        a.at(i)=x*1000000+i+1;
    }
    rep(i,N){
        s.insert(a.at(i));
    }
    sort(all(a));
    for(ll i=1;i<=M;i++){
        ll pos=binary_search(i);
        out(pos);
    }
}