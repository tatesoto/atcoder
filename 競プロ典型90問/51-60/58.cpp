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

ll Sum(ll n){
    ll res=0;
    while(n>0){
        res += n%10;
        n/=10;
    }
    return res;
}

ll pushA(ll x){
    ll ans=x;
    ans+=Sum(x);
    ans%=100000;
    return ans;
}

int main() {
    ll N,K;cin>>N>>K;
    vector<ll> v;
    vector<ll> check(100000,-1);
    bool stop=false;
    ll cnt=0;
    ll now=N;
    //{ループに到達する回数,ループの周期}
    pair<ll,ll> ST;
    check.at(now)=0;
    v.push_back(now);
    while(true){
        now=pushA(now);
        cnt++;
        if(check.at(now)!=-1){
            ST={check.at(now),cnt-check.at(now)};
            break;
        }
        check.at(now)=cnt;
        v.push_back(now);
    }
    ll k=K-ST.first;
    if(k<0){
        out(v.at(K));
    }
    else{
        k%=ST.second;
        out(v.at(ST.first+k));
    }
}