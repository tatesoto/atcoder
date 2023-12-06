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

ll NtoTen(string s,ll n){
    ll ans=0;
    rep(i,s.size()){
        ll x=s.at(i)-'0';
        ans*=n;
        ans+=x;
    }
    return ans;
}

string TentoN(ll m,ll n){
    string ans;
    if(m==0){
        return "0";
    }
    while(m>0){
        ll x=m%n;
        char c='0'+x;
        ans=c+ans;
        m/=n;
    }
    return ans;
}

int main() {
    string N;cin>>N;
    ll K;cin>>K;
    rep(i,K){
        N=TentoN(NtoTen(N,8),9);
        for(ll i=0;i<N.size();i++){
            if(N.at(i)=='8'){
                N.at(i)='5';
            }
        }
    }
    out(N);
}