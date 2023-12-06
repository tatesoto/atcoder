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
    map<ll,ll> mp;
    rep(i,N){
        cin>>a.at(i);
        mp[i]=a.at(i);
    }
    ll base=0;
    ll Q;cin>>Q;
    rep(i,Q){
        ll c;cin>>c;
        if(c==1){
            ll x;cin>>x;
            base=x;
            mp.clear();
        }
        else if(c==2){
            ll iq,x;cin>>iq>>x;
            iq--;
            mp[iq]+=x;
        }
        else{
            ll iq;cin>>iq;
            iq--;
            out(base+mp[iq]);
        }
    }
}