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
    string S;cin>>S;
    vector<ll> left(N);
    ll opos=-1;
    ll xpos=-1;
    rep(i,N){
        if(S.at(i)=='o'){
            opos=i;
            left.at(i)=xpos;
        }
        else{
            xpos=i;
            left.at(i)=opos;
        }
    }
    ll ans=0;
    for(ll r=N-1;r>=0;r--){
        ans+=left.at(r)+1;
    }
    out(ans);
}