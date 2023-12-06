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
    vector<ll> a;
    rep(i,N){
        a.push_back(i+1);
    }
    ll reverse=1;
    rep(i,Q){
        ll q;cin>>q;
        if(q==1){
            ll x,y;
            cin>>x>>y;
            x--;
            if(reverse==-1){
                x=N-1-x;
            }
            a.at(x)=y;
        }
        else if(q==2){
            reverse*=-1;
        }
        else{
            ll x;cin>>x;
            x--;
            if(reverse==-1){
                x=N-1-x;
            }
            out(a.at(x));
        }
    }
}