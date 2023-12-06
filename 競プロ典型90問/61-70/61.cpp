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
    ll Q;cin>>Q;
    deque<ll> dq;
    rep(i,Q){
        ll t,x;cin>>t>>x;
        if(t==1){
            dq.push_front(x);
        }
        else if(t==2){
            dq.push_back(x);
        }
        else{
            x--;
            out(dq.at(x));
        }
    }
}