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
    ll N;cin>>N;
    out(TentoN(N,2));
}