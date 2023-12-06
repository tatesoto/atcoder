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
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N;cin>>N;
    ll Q;cin>>Q;
    queue<ll> q;
    rep(i, N){
        q.push(i+1);
    }
    set<ll> called;
    rep(i, Q){
        ll c;cin>>c;
        if(c == 1){
            ll x = q.front();
            q.pop();
            called.insert(x);
        }
        else if(c == 2){
            ll x;cin>>x;
            called.erase(x);
        }
        else{
            ll x = *called.begin();
            out(x);
        }
    }
}