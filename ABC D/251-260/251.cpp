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
    ll W;cin>>W;
    vector<ll> v;
    for(ll i=1;i<=99;i++){
        v.push_back(i);
        v.push_back(i*100);
        v.push_back(i*10000);
    }
    v.push_back(1000000);
    out(v.size());
    for(ll i=0;i<v.size();i++){
        cout<<v.at(i);
        if(i!=v.size()-1){
            cout<<" ";
        }
    }
    cout<<endl;
}