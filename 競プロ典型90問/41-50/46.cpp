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
    ll N;cin>>N;
    map<ll,ll> a,b,c;
    rep(i,N){
        ll A;cin>>A;
        A%=46;
        a[A]++;
    }
    rep(i,N){
        ll B;cin>>B;
        B%=46;
        b[B]++;
    }
    rep(i,N){
        ll C;cin>>C;
        C%=46;
        c[C]++;
    }
    ll ans=0;
    rep(i,46){
        if(!a.count(i)) continue;
        rep(j,46){
            if(!b.count(j)) continue;
            ll k=(46*3-i-j)%46;
            if(!c.count(k)) continue;
            ans+=a[i]*b[j]*c[k];
        }
    }
    out(ans);
}