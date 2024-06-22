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
    string s,t;cin>>s>>t;
    ll ssiz=s.size();
    ll tsiz=t.size();
    s='0'+s;
    t='1'+t;
    vector<vector<ll>> dp(ssiz+1,vector<ll>(tsiz+1,-1));
    string ans="";
    rep(i,ssiz+1){
        dp.at(i).at(0)=0;
    }
    rep(j,tsiz+1){
        dp.at(0).at(j)=0;
    }
    for(ll i=1;i<=ssiz;i++){
        for(ll j=1;j<=tsiz;j++){
            if(s.at(i)==t.at(j)){
                dp.at(i).at(j)=dp.at(i-1).at(j-1)+1;
            }
            else{
                dp.at(i).at(j)=max(dp.at(i-1).at(j),dp.at(i).at(j-1));
            }
        }
    }
    ll len=dp.at(ssiz).at(tsiz);
    ll i=ssiz;
    ll j=tsiz;
    while(len>0){
        if(s.at(i)==t.at(j)){
            ans+=s.at(i);
            i--;
            j--;
            len--;
        }
        else if(dp.at(i-1).at(j)==dp.at(i).at(j)){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(all(ans));
    out(ans);
}