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
    ll N,Q;cin>>N>>Q;
    vector<ll> a(N),b(N-1);
    rep(i,N){
        cin>>a.at(i);
    }
    ll uncf=0;
    for(ll i=0;i<N-1;i++){
        b.at(i)=a.at(i+1)-a.at(i);
        uncf+=abs(a.at(i)-a.at(i+1));
    }
    rep(i,Q){
        ll l,r,v;cin>>l>>r>>v;
        l--;r--;
        ll before=0;
        ll after=0;
        if(l>=1){
            before+=abs(b.at(l-1));
            b.at(l-1)+=v;
            after+=abs(b.at(l-1));
        }
        if(r<N-1){
            before+=abs(b.at(r));
            b.at(r)-=v;
            after+=abs(b.at(r));
        }
        uncf+=after-before;
        out(uncf);
    }
}