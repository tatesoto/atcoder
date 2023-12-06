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
    ll N,x,y;cin>>N>>x>>y;
    vector<ll> a(N+1);
    for(ll i=1;i<=N;i++) cin>>a.at(i);
    set<ll> X,Y;
    X.insert(a.at(1));
    Y.insert(0);
    for(ll i=2;i<=N;i++){
        if(i%2==1){
            set<ll> tmp;
            for(auto nx:X){
                tmp.insert(nx+a.at(i));
                tmp.insert(nx-a.at(i));
            }
            X=tmp;
        }
        else{
            set<ll> tmp;
            for(auto ny:Y){
                tmp.insert(ny+a.at(i));
                tmp.insert(ny-a.at(i));
            }
            Y=tmp;
        }
    }
    if(X.count(x)&&Y.count(y)){
        out("Yes");
    }
    else{
        out("No");
    }
}