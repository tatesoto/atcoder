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

int main() {
    ll K;cin>>K;
    ll cnt=0;
    for(ll i=1;i*i*i<=K;i++){
        if(K%i!=0) continue;
        for(ll j=i;i*j*j<=K;j++){
            if(K%(i*j)==0&&j<=K/(i*j)){
                cnt++;
            }
        }
    }
    out(cnt);
}