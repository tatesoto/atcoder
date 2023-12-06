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

ll N;

bool isOK(ll i,ll j) {
    if (i*i*i+i*i*j+i*j*j+j*j*j>=N) return true;
    else return false;
}

ll binary_search(ll i) {
    ll ng = i-1;
    ll ok = 1000000;

    while (ok - ng> 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(i,mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main() {
    cin>>N;
    ll X=INF;
    for(ll i=0;i<=700000;i++){
        ll x=binary_search(i);
        chmin(X,i*i*i+i*i*x+i*x*x+x*x*x);
    }
    out(X);
}