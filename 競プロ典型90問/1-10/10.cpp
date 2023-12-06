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
    vector<pair<ll,ll>> v(N+1);
    for(ll i=1;i<=N;i++){
        ll c,p;cin>>c>>p;
        v.at(i)=make_pair(c,p);
    }
    vector<ll> s1(N+1,0);
    vector<ll> s2(N+1,0);
    for(ll i=1;i<=N;i++){
        s1.at(i)=s1.at(i-1);
        s2.at(i)=s2.at(i-1);
        if(v.at(i).first==1){
            s1.at(i)+=v.at(i).second;
        }
        else{
            s2.at(i)+=v.at(i).second;
        }
    }
    ll Q;cin>>Q;
    rep(i,Q){
        ll l,r;cin>>l>>r;
        ll x=s1.at(r)-s1.at(l-1);
        ll y=s2.at(r)-s2.at(l-1);
        out(x<<" "<<y);
    }
}