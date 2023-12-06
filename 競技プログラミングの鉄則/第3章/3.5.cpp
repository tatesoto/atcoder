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
    ll N;
    cin>>N;
    vector<ll> a(N),b(N),c;
    rep(i,N) cin>>a.at(i);
    rep(i,N) c.push_back(a.at(i));
    sort(all(c));
    c.erase(unique(all(c)),c.end());
    rep(i,N){
        auto iter=lower_bound(all(c),a.at(i));
        ll pos=distance(c.begin(),iter);
        b.at(i)=pos+1;
    }
    rep(i,N){
        cout<<b.at(i);
        if(i<N-1){
            cout<<" ";
        }
    }
    cout<<endl;
}