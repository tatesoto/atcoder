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
    multiset<ll> A;
    ll Q;cin>>Q;
    rep(i,5){
        A.insert(-1);
        A.insert(INF);
    }
    rep(i,Q){
        ll c;cin>>c;
        if(c == 1){
            ll x;cin>>x;
            A.insert(x);
        }
        else if(c == 2){
            ll x,k;cin>>x>>k;
            auto iter = A.upper_bound(x);
            rep(j, k){
                iter--;
            }
            out(*iter);
        }
        else{
            ll x,k;cin>>x>>k;
            k--;
            auto iter = A.lower_bound(x);
            rep(j, k){
                iter++;
            }
            if(*iter == INF){
                out(-1);
            }
            else{
                out(*iter);
            }
        }
    }
}