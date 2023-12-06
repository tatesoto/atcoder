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
    ll N,K;cin>>N>>K;
    queue<ll> q;
    rep(i,N){
        ll a;cin>>a;
        q.push(a);
    }
    rep(i,K){
        q.pop();
        q.push(0);
    }
    while(!q.empty()){
        cout<<q.front();
        q.pop();
        if(q.empty()){
            cout<<endl;
            return 0;
        }
        cout<<" ";
    }
}