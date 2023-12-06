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

int main() {
    ll Q; cin>>Q;
    queue<string> q;
    rep(i,Q){
        ll x; cin>>x;
        if(x==1){
            string s; cin>>s;
            q.push(s);
        }
        else if(x==2){
            out(q.front());
        }
        else{
            q.pop();
        }
    }
}