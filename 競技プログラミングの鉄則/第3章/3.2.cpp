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

int main() {
    ll N,K;cin>>N>>K;
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    ll left=-1;
    ll right=pow(10,9);
    while(abs(right-left)>1){
        ll mid=(left+right)/2;
        ll sum=0;
        rep(i,N){
            sum+=mid/a.at(i);
        }
        if(sum>=K) right=mid;
        else left=mid;

    }
    out(right);
}