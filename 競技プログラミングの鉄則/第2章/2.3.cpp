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
    ll H,W;cin>>H>>W;
    vector<vector<ll>> a(H+1,vector<ll>(W+1));
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            cin>>a.at(i).at(j);
        }
    }
    vector<vector<ll>> s(H,vector<ll>(W+1,0));
    rep(i,H){
        for(ll j=0;j<W;j++){
            s.at(i).at(j+1)=s.at(i).at(j)+a.at(i).at(j);
        }
    }
    ll Q;cin>>Q;
    rep(i,Q){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;
        b--;
        c--;
        d--;
        ll ans=0;
        for(ll j=a;j<=c;j++){
            ans+=s.at(j).at(d+1)-s.at(j).at(b);
        }
        out(ans);
    }
}