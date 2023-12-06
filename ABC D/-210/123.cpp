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

ll X, Y, Z, K;
vector<ll> C, D;
bool check(ll x){
    ll cnt = 0;
    rep(i, Z){
        ll y = x - C.at(i);
        auto iter = lower_bound(all(D), y);
        cnt += D.size() - distance(D.begin(), iter);
    }
    if(cnt >= K) return true;
    else return false;
}

int main() {
    cin>>X>>Y>>Z>>K;
    vector<ll> A(X), B(Y);
    C.resize(Z);
    D.clear();
    rep(i, X) cin>>A.at(i);
    rep(i, Y) cin>>B.at(i);
    rep(i, Z) cin>>C.at(i);
    rep(i, X){
        rep(j, Y){
            D.push_back(A.at(i) + B.at(j));
        }
    }
    sort(all(C));
    sort(all(D));
    ll ok = 0;
    ll ng = 1e11;
    while(ng - ok > 1){
        ll mid = (ok + ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    reverse(all(C));
    reverse(all(D));
    priority_queue<ll> pq;
    rep(i, Z){
        if(C.at(i) + D.at(0) <= ok) break;
        rep(j, D.size()){
            if(C.at(i) + D.at(j) <= ok) break;
            pq.push(C.at(i) + D.at(j));
        }
    }
    rep(i, K){
        if(pq.empty()) out(ok);
        else{
            out(pq.top());pq.pop();
        }
    }
}