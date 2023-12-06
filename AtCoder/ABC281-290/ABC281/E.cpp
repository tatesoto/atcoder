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
    ll N,M,K;cin>>N>>M>>K;
    vector<ll> A(N+1);
    rep(i,N) cin>>A.at(i+1);
    multiset<ll> tmp,L,R;
    rep(i,M) tmp.insert(A.at(i+1));
    for(auto x:tmp){
        L.insert(x);
        if(L.size()==K) break;
    }
    for(ll i=M+1;i<=N;i++) R.insert(A.at(i));
    ll cnt=0;
    for(auto x:tmp){
        if(cnt<K){
            cnt++;
            continue;
        }
        R.insert(x);
    }
    
}