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
    ll N,X;cin>>N>>X;
    string S;cin>>S;
    string bi;
    rep(i,64){
        if(X&1){
            bi="1"+bi;
        }
        else{
            bi="0"+bi;
        }
        X>>=1;
    }
    rep(i,N){
        if(S.at(i)=='U'){
            bi.pop_back();
        }
        else if(S.at(i)=='L'){
            bi+="0";
        }
        else{
            bi+="1";
        }
    }
    vector<ll> two;
    ll tmp=1;
    ll ans=0;
    rep(i,64){
        two.push_back(tmp);
        tmp*=2;
    }
    reverse(all(bi));
    rep(i,min((ll)bi.size(),64LL)){
        if(bi.at(i)=='1'){
            ans+=two.at(i);
        }
    }
    out(ans);
}