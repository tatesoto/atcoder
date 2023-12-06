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
    for(ll i=0;i<N;i++){
        cin>>a.at(i);
    }
    ll shift=0;
    rep(i,Q){
        ll t;cin>>t;
        if(t==1){
            ll x,y;cin>>x>>y;
            x--;y--;
            x-=shift;
            y-=shift;
            x%=N;y%=N;
            if(x<0){
                x+=N;
            }
            if(y<0){
                y+=N;
            }
            swap(a.at(x),a.at(y));
        }
        else if(t==2){
            ll x,y;cin>>x>>y;
            shift++;
        }
        else{
            ll x,y;cin>>x>>y;
            x--;
            x-=shift;
            x%=N;
            if(x<0){
                x+=N;
            }
            out(a.at(x));
        }
    }
}