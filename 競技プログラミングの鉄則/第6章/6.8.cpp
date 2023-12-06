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
    ll N,L;cin>>N>>L;
    set<ll> e,w;
    rep(i,N){
        ll a;
        string b;
        cin>>a>>b;
        if(b=="E"){
            e.insert(a);
        }
        else{
            w.insert(a);
        }
    }
    ll E=L;
    ll W=0;
    if(!e.empty()){
        auto eitr=e.begin();
        E=*eitr;
    }
    if(!w.empty()){
        auto witr=w.end();
        witr--; 
        W=*witr; 
    }
    out(max(L-E,W));
}