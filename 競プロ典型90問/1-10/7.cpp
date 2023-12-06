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
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    sort(all(a));
    ll Q;cin>>Q;
    rep(i,Q){
        ll ans=0;
        ll b;cin>>b;
        ll idx=distance(a.begin(),lower_bound(all(a),b));
        if(idx==0){
            ans=abs(b-a.at(idx));
        }
        else if(idx==N){
            ans=abs(b-a.at(N-1));
        }
        else{
            ans=min(abs(b-a.at(idx)),abs(b-a.at(idx-1)));
        }
        out(ans);
    }
}