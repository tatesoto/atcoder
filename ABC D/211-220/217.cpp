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
    ll L,Q;cin>>L>>Q;
    set<ll> s;
    s.insert(0);
    s.insert(L);
    rep(i,Q){
        ll c,x;cin>>c>>x;
        if(c==1){
            s.insert(x);
        }
        else{
            s.insert(x);
            auto iter1=s.find(x);
            auto iter2=s.find(x);
            iter1++;
            iter2--;
            ll l=*iter1;
            l-=*iter2;
            out(l);
            s.erase(x);
        }
    }
}