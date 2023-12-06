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
    ll N,C;cin>>N>>C;
    vector<pair<ll,ll>> oper(N);
    rep(i, N) cin>>oper.at(i).first>>oper.at(i).second;
    vector<ll> operation0, operation1;
    ll s = 0;
    ll t = 1;
    rep(i, N){
        ll T = oper.at(i).first;
        ll A = oper.at(i).second;
        if(T == 1){
            s &= A;
            t &= A;
        }
        else if(T == 2){
            s |= A;
            t |= A;
        }
        else{
            s ^= A;
            t ^= A;
        }
        operation0.push_back(s);
        operation1.push_back(t);
    }
    ll X = C;
    rep(i, N){
        
    }
}