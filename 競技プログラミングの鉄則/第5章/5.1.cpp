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

//素数判定
bool prime_judge(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return n!=1;
}

int main() {
    ll Q;cin>>Q;
    rep(i,Q){
        ll X;cin>>X;
        if(prime_judge(X)){
            out("Yes");
        }
        else{
            out("No");
        }
    }
}