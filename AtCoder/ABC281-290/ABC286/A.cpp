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
    ll p,q,r,s;cin>>p>>q>>r>>s;
    p--;
    q--;
    r--;
    s--;
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    rep(i,N){
        if(p <= i && i <= q){
            cout<<a.at(r + i-p);
        }
        else if(r <= i && i <= s){
            cout<<a.at(p + i-r);
        }
        else{
            cout<<a.at(i);
        }
        if(i<N-1){
            cout<<" ";
        }
        else{
            cout<<endl;
        }
    }
}