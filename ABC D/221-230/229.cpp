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
    string S;cin>>S;
    ll K;cin>>K;
    vector<ll> period(S.size()+1,0);
    for(ll i=1;i<=S.size();i++){
        period.at(i)=period.at(i-1);
        if(S.at(i-1)=='.'){
            period.at(i)++;
        }
    }
    vector<ll> x(S.size(),0);
    ll r=0;
    for(ll i=0;i<S.size();i++){
        while(true){
            if(r==S.size()) break;
            if(S.at(r)=='X') r++;
            else if(period.at(r+1)-period.at(i)<=K) r++;
            else break;
        }
        x.at(i)=r;
    }
    ll ans=0;
    rep(i,S.size()){
        chmax(ans,x.at(i)-i);
    }
    out(ans);
}