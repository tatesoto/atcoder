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
    rep(i,N){
        cin>>a.at(i);
    }
    ll XOR_sum=a.at(0);
    for(ll i=1;i<=N-1;i++){
        XOR_sum^=a.at(i);
    }
    if(XOR_sum!=0){
        out("First");
    }
    else{
        out("Second");
    }
}