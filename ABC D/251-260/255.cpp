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
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    sort(all(a));
    vector<ll> s(N+1,0); //すべて0のN+1個の配列
    for(ll i=0;i<N;i++){
        s.at(i+1)=s.at(i)+a.at(i); //帰納的に埋めていく
    }
    rep(i,Q){
        ll x;cin>>x;
        ll pos=lower_bound(all(a),x)-a.begin();
        if(pos==N){
            out(x*N-s.at(N));
        }
        else{
            ll left=pos*x-(s.at(pos)-s.at(0));
            ll right=s.at(N)-s.at(pos)-x*(N-pos);
            out(left+right);
        }
    }
}