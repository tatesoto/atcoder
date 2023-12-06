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
    vector<pair<ll,ll>> movie;
    rep(i,N){
        ll l,r;cin>>l>>r;
        movie.push_back(make_pair(r,l));
    } 
    sort(all(movie));
    ll now=0;
    ll start=0;
    ll ans=0;
    while(1){
        bool judge=true;
        for(ll i=start;i<N;i++){
            ll l=movie.at(i).second;
            ll r=movie.at(i).first;
            if(l>=now){
                start=i+1;
                now=r;
                ans++;
                judge=false;
                break;
            }
        }
        if(judge){
            break;
        }
    }
    out(ans);
}