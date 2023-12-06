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

//素因数分解
map<ll,ll> prime_factor(ll N){
    map<ll,ll> ans;
    for(ll i=2;i*i<=N;i++){
        while(N%i==0){
            ans[i]++;
            N/=i;
        }
    }
    if(N!=1){
        ans[N]=1;
    }
    return ans;
}

ll factor_cnt(ll n,ll m){
    ll ans=0;
    ll cnt=m;
    while(cnt>0){
        ans+=n;
        ll div=ans;
        while(true){
            if(div%n!=0){
                break;
            }
            div/=n;
            cnt--;
        }
    }
    return ans;
}

int main() {
    ll K;cin>>K;
    map<ll,ll> mp;
    mp=prime_factor(K);
    ll ans=-1;
    for(auto p:mp){
        ll now=factor_cnt(p.first,p.second);
        chmax(ans,now);
    }
    out(ans);
}