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

ll N;
Graph A;
set<ll> s;
ll ans;

void dance(set<ll> s, ll tmp){
    if(s.empty()){
        chmax(ans, tmp);
        return;
    }
    ll pos = *s.begin();
    s.erase(pos);
    set<ll> next = s;
    while(!next.empty()){
        ll x = tmp;
        ll p = *next.begin();
        next.erase(p);
        x^= A.at(pos).at(p);
        s.erase(p);
        dance(s, x);
        s.insert(p);
    }
}


int main() {
    cin>>N;
    A.resize(2*N,vector<ll>(2*N));
    rep(i,2*N){
        for(ll j=i+1;j<2*N;j++){
            cin>>A.at(i).at(j);
        }
    }
    rep(i,2*N) s.insert(i);
    ans = 0;
    dance(s, 0);
    out(ans);
}