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
    vector<ll> a(N),b(N),c(N),d(N);
    rep(i,N) cin>>a.at(i);
    rep(i,N) cin>>b.at(i);
    rep(i,N) cin>>c.at(i);
    rep(i,N) cin>>d.at(i);
    vector<ll> absum,cdsum;
    rep(i,N){
        rep(j,N){
            absum.push_back(a.at(i)+b.at(j));
            cdsum.push_back(c.at(i)+d.at(j));
        }
    }
    sort(all(cdsum));
    rep(i,N*N){
        ll c=K-absum.at(i);
        ll pos=lower_bound(all(cdsum),c)-cdsum.begin();
        if(pos<N*N && cdsum.at(pos)==c){
            out("Yes");
            return 0;
        }
    }
    out("No");
}