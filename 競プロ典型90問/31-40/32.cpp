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
    vector<vector<ll>> a(N+1,vector<ll>(N+1));
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            cin>>a.at(i).at(j);
        }
    }
    ll M;cin>>M;
    set<ll> s;
    rep(i,M){
        ll x,y;cin>>x>>y;
        s.insert(100*x+y);
        s.insert(100*y+x);
    }
    vector<ll> p;
    for(ll i=1;i<=N;i++){
        p.push_back(i);
    }
    ll ans=INF;
    do{
        ll x=0;
        for(ll i=0;i<N;i++){
            if(i!=N-1){
                if(s.count(100*p.at(i)+p.at(i+1))){
                    x=INF;
                    break;
                }
                else{
                    x+=a.at(p.at(i)).at(i+1);
                }
            }
            else{
                x+=a.at(p.at(i)).at(i+1);
            }
        }
        chmin(ans,x);
    } while (next_permutation(all(p)));
    if(ans==INF) ans=-1;
    out(ans);
}