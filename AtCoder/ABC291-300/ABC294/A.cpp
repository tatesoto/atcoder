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
    vector<ll> v;
    rep(i, N){
        ll a;cin>>a;
        if(a%2==1){
            v.push_back(a);
        }
    }
    rep(i, v.size()){
        cout<<v.at(i);
        if(i != v.size()-1){
            cout<<" ";
        }
    }
    cout<<endl;
}