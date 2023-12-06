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
    vector<ll> a(N+2,INF);
    for(ll i=1;i<=N;i++) cin>>a.at(i);
    ll count=0;
    ll right=1;
    for(ll i=1;i<N;i++){
        while(a.at(right)-a.at(i)<=K){
            right++;
        }
        right--;
        count+=right-i;
    }
    out(count);
}