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
    ll N,M;cin>>N>>M;
    vector<ll> a(N+1),b(M+1),c(N+M+1);
    rep(i,N+1) cin>>a.at(i);
    rep(i,N+M+1) cin>>c.at(i);
    for(ll i=M;i>=0;i--){
        ll sum=0;
        for(ll j=N-1;j>=max(0LL,i+N-M);j--){
            sum+=a.at(j)*b.at(N+i-j);
        }
        b.at(i)=(c.at(N+i)-sum)/a.at(N);
    }
    rep(i,M+1){
        cout<<b.at(i);
        if(i!=M){
            cout<<" ";
        }
    }
    cout<<endl;
}